#include"bindresponse.h"

#include<cassert>

#include<angelscript.h>

#include"scriptingservice.h"
#include"../response.h"


namespace chttpm
{
	BindResponse::BindResponse(Response& response) :
		m_Response(response)
	{
	}



	BindResponse::~BindResponse()
	{
	}



	int BindResponse::GetStatusCode() const
	{
		return m_Response.statusCode;
	}



	void BindResponse::SetStatusCode(int statusCode)
	{
		m_Response.statusCode = statusCode;
	}



	std::string BindResponse::GetBody() const
	{
		return m_Response.body;
	}



	void BindResponse::SetBody(std::string& body)
	{
		m_Response.body = body;
	}



	void BindResponse::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("Response", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("Response", scriptingService);
	}



	void BindResponse::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Properties
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "int get_statusCode() const property", asMETHOD(BindResponse, GetStatusCode), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "void set_statusCode(int) property", asMETHOD(BindResponse, SetStatusCode), asCALL_THISCALL); assert(r >= 0);

		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "string get_body() const property", asMETHOD(BindResponse, GetBody), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "void set_body(string) property", asMETHOD(BindResponse, SetBody), asCALL_THISCALL); assert(r >= 0);
	}
}
