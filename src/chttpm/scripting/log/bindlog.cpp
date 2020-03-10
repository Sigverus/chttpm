#include"bindlog.h"

#include<cassert>

#include<angelscript.h>

#include"../scriptingservice.h"
#include"../../log/log.h"



namespace chttpm
{
	BindMessageLoggerKeys::BindMessageLoggerKeys(MessageLoggerKeys messageLoggerKeys) :
		m_MessageLoggerKeys(messageLoggerKeys)
	{
	}



	BindMessageLoggerKeys& BindMessageLoggerKeys::Str(std::string key, std::string value)
	{
		m_MessageLoggerKeys.Str(key, value);
		return *this;
	}



	void BindMessageLoggerKeys::Msg(std::string message) const
	{
		m_MessageLoggerKeys.Msg(message);
	}



	void BindMessageLoggerKeys::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Register object.
		r = scriptingService.scriptEngine->RegisterObjectType("MessageLoggerKeys", 0, asOBJ_REF); assert(r >= 0);

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("MessageLoggerKeys", "MessageLoggerKeys& Str(string, string)", asMETHOD(BindMessageLoggerKeys, Str), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("MessageLoggerKeys", "void Msg(string) const", asMETHOD(BindMessageLoggerKeys, Msg), asCALL_THISCALL); assert(r >= 0);

		// Helpers
		BindReference::RegisterIntoScriptingService("MessageLoggerKeys", scriptingService);
	}



	BindBuilderLoggerKeys::BindBuilderLoggerKeys(BuilderLoggerKeys builderLoggerKeys) :
		m_BuilderLoggerKeys(builderLoggerKeys)
	{
	}



	BindBuilderLoggerKeys& BindBuilderLoggerKeys::Str(std::string key, std::string value)
	{
		m_BuilderLoggerKeys.Str(key, value);
		return *this;
	}



	BindLogger* BindBuilderLoggerKeys::Logger() const
	{
		return new BindLogger{ m_BuilderLoggerKeys.Logger() };
	}



	void BindBuilderLoggerKeys::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Register logger type, it is needed to succeed here.
		// TODO : separate types registering from their methods, due to cyclic return types
		r = scriptingService.scriptEngine->RegisterObjectType("Logger", 0, asOBJ_REF); assert(r >= 0);

		// Register object.
		r = scriptingService.scriptEngine->RegisterObjectType("BuilderLoggerKeys", 0, asOBJ_REF); assert(r >= 0);

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("BuilderLoggerKeys", "BuilderLoggerKeys& Str(string, string)", asMETHOD(BindBuilderLoggerKeys, Str), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("BuilderLoggerKeys", "Logger@ Logger() const", asMETHOD(BindBuilderLoggerKeys, Logger), asCALL_THISCALL); assert(r >= 0);

		// Helpers
		BindReference::RegisterIntoScriptingService("BuilderLoggerKeys", scriptingService);
	}



	BindLogger::BindLogger(Logger logger) :
		m_Logger(logger)
	{
	}



	BindMessageLoggerKeys* BindLogger::Info() const
	{
		return new BindMessageLoggerKeys{ m_Logger.Info() };
	}



	BindBuilderLoggerKeys* BindLogger::With() const
	{
		return new BindBuilderLoggerKeys{ m_Logger.With() };
	}



	BindLogger& BindLogger::OpAssign(const BindLogger& other)
	{
		this->m_Logger = other.m_Logger;
		return *this;
	}



	BindLogger *BindLoggerFactory()
	{
		return new BindLogger{ Logger{} };
	}



	void BindLogger::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		// Helpers
		BindReference::RegisterIntoScriptingService("Logger", scriptingService);

		int r;

		// Register object.
		//r = scriptingService.scriptEngine->RegisterObjectType("Logger", 0, asOBJ_REF); assert(r >= 0);

		// Factory
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Logger", asBEHAVE_FACTORY, "Logger@ f()", asFUNCTION(BindLoggerFactory), asCALL_CDECL); assert(r >= 0);

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "MessageLoggerKeys@ Info() const", asMETHOD(BindLogger, Info), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "BuilderLoggerKeys@ With() const", asMETHOD(BindLogger, With), asCALL_THISCALL); assert(r >= 0);

		// Operators
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "Logger& opAssign(const Logger&)", asMETHOD(BindLogger, OpAssign), asCALL_THISCALL);

	}
}
