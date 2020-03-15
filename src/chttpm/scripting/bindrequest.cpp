#include"bindrequest.h"

#include<cassert>

#include<angelscript.h>

#include"scriptingservice.h"
#include"bindqueryparameters.h"
#include"../request.h"



namespace chttpm
{
	BindRequest::BindRequest(const Request& request) :
		m_Request(request)
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



	const BindQueryParameters* BindRequest::GetQueryParameters() const
	{
		// TODO : I don't want to instantiate a new BindQueryParameters every call, but
		// I'm finding it hard to find a solution that balances well flexibility with safety.
		// Not wanting to let Angel Script intrude within the types makes this harder, though.
		return new BindQueryParameters{ m_Request.queryParameters };
	}



	void BindRequest::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("Request", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("Request", scriptingService);
	}



	void BindRequest::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Properties
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_method() const property", asMETHOD(BindRequest, GetMethod), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_target() const property", asMETHOD(BindRequest, GetTarget), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "const QueryParameters@ get_queryParameters() const property", asMETHOD(BindRequest, GetQueryParameters), asCALL_THISCALL); assert(r >= 0);
	}
}
