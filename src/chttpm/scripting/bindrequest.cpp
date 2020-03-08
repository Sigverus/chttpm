#include"bindrequest.h"

#include<cassert>
#include<iostream>

#include<angelscript.h>

#include"scriptingservice.h"
#include"../request.h"



namespace chttpm
{
	BindRequest::BindRequest(const Request& request) :
		m_Request(request)
	{
	}



	BindRequest::~BindRequest()
	{
	}



	std::string BindRequest::GetMethod() const
	{
		return m_Request.method;
	}



	std::string BindRequest::GetTarget() const
	{
		return m_Request.target;
	}



	void BindRequest::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Register object.
		r = scriptingService.scriptEngine->RegisterObjectType("Request", 0, asOBJ_REF); assert(r >= 0);

		// Properties
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_method() const property", asMETHOD(BindRequest, GetMethod), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_target() const property", asMETHOD(BindRequest, GetTarget), asCALL_THISCALL); assert(r >= 0);

		// Helpers
		BindReference::RegisterIntoScriptingService("Request", scriptingService);
	}
}
