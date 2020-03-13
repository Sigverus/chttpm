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
		// TODO : since query parameters are sure to exist in m_Request, it is possible to avoid new allocations.
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
