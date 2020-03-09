#include"scriptingservice.h"

#include<cassert>
#include<iostream>

#include<angelscript.h>
#include<scriptbuilder/scriptbuilder.h>
#include<scriptstdstring/scriptstdstring.h>

#include"bindrequest.h"
#include"../request.h"

#include"bindresponse.h"
#include"../response.h"



namespace chttpm
{
	void MessageCallback(const asSMessageInfo *msg, void *param)
	{
		const char *type = "ERR ";
		if (msg->type == asMSGTYPE_WARNING)
			type = "WARN";
		else if (msg->type == asMSGTYPE_INFORMATION)
			type = "INFO";
		printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
	}



	void print(const std::string& message)
	{
		std::cout << message << std::endl;
	}



	ScriptingService::ScriptingService()
	{
		scriptEngine = asCreateScriptEngine();
		scriptEngine->SetEngineProperty(asEP_PROPERTY_ACCESSOR_MODE, 3);
		RegisterStdString(scriptEngine);

		int r;
		r = scriptEngine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert(r >= 0);
		r = scriptEngine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(print), asCALL_CDECL); assert(r >= 0);

	}



	ScriptingService::~ScriptingService()
	{
		if (scriptEngine != nullptr)
			scriptEngine->ShutDownAndRelease();
	}



	void ScriptingService::LoadModule(const char* moduleName, const char *scriptFile)
	{
		CScriptBuilder scriptBuilder{};
		int r = scriptBuilder.StartNewModule(scriptEngine, moduleName);
		if (r < 0)
		{
			std::cout << "Failed to start new module " << moduleName << std::endl;
			return;
		}

		r = scriptBuilder.AddSectionFromFile(scriptFile);
		if (r < 0)
		{
			std::cout << "Failed to load script file." << std::endl;
			return;
		}

		r = scriptBuilder.BuildModule();
		if (r < 0)
		{
			std::cout << "Found errors in the script file." << std::endl;
			return;
		}
	}



	void ScriptingService::LoadModuleFromMemory(const char* moduleName, const char* moduleCode)
	{
		CScriptBuilder scriptBuilder{};
		int r = scriptBuilder.StartNewModule(scriptEngine, moduleName);
		if (r < 0)
		{
			std::cout << "Failed to start new module " << moduleName << std::endl;
			return;
		}

		r = scriptBuilder.AddSectionFromMemory("moduleName", moduleCode);
		if (r < 0)
		{
			std::cout << "Failed to load script file." << std::endl;
			return;
		}

		r = scriptBuilder.BuildModule();
		if (r < 0)
		{
			std::cout << "Found errors in the script file." << std::endl;
			return;
		}
	}



	void ScriptingService::ProcessRequest(const char *moduleName, const Request& request, Response& response) const
	{
		auto *scriptModule = scriptEngine->GetModule(moduleName);
		auto *scriptEntryPoint = scriptModule->GetFunctionByDecl("void ProcessRequest(const Request&, Response&)");
		if (scriptEntryPoint == nullptr)
		{
			std::cout << "Entry point function 'void ProcessRequest(const Request&, Response&)' was not found." << std::endl;
			// TODO : throw an exception here?
			return;
		}


		auto *scriptExecutionContext = scriptEngine->CreateContext();
		scriptExecutionContext->Prepare(scriptEntryPoint);

		BindRequest scriptedRequest{ request };
		BindResponse scriptedResponse{ response };
		scriptExecutionContext->SetArgObject(0, &scriptedRequest);
		scriptExecutionContext->SetArgObject(1, &scriptedResponse);

		int r = scriptExecutionContext->Execute();
		if (r != asEXECUTION_FINISHED)
		{
			if (r == asEXECUTION_EXCEPTION)
			{
				std::cout <<
					"Exception (" << scriptExecutionContext->GetExceptionFunction() <<
					":" << scriptExecutionContext->GetExceptionLineNumber() <<
					"): " << scriptExecutionContext->GetExceptionString() << std::endl;
			}
			else
			{
				std::cout << "Execution finished with error" << std::endl;
			}
		}

		scriptExecutionContext->Release();
	}
}

