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
		if (m_WeakReferenceFlag)
		{
			m_WeakReferenceFlag->Set(true);
			m_WeakReferenceFlag->Release();
		}
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



	int BindResponse::AddRef()
	{
		return ++m_ReferencesCount;
	}



	int BindResponse::Release()
	{
		if (--m_ReferencesCount == 0)
			delete this;

		return m_ReferencesCount;
	}



	asILockableSharedBool* BindResponse::GetWeakRefFlag()
	{
		if (m_WeakReferenceFlag == nullptr)
			m_WeakReferenceFlag = asCreateLockableSharedBool();

		return m_WeakReferenceFlag;
	}



	void BindResponse::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Register object.
		r = scriptingService.scriptEngine->RegisterObjectType("Response", 0, asOBJ_REF); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Response", asBEHAVE_ADDREF, "void f()", asMETHOD(BindResponse, AddRef), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Response", asBEHAVE_RELEASE, "void f()", asMETHOD(BindResponse, Release), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Response", asBEHAVE_GET_WEAKREF_FLAG, "int &f()", asMETHOD(BindResponse, GetWeakRefFlag), asCALL_THISCALL); assert(r >= 0);


		// Properties
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "int get_statusCode() const property", asMETHOD(BindResponse, GetStatusCode), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "void set_statusCode(int) property", asMETHOD(BindResponse, SetStatusCode), asCALL_THISCALL); assert(r >= 0);

		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "string get_body() const property", asMETHOD(BindResponse, GetBody), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Response", "void set_body(string) property", asMETHOD(BindResponse, SetBody), asCALL_THISCALL); assert(r >= 0);
	}
}
