#include"bindrequest.h"

#include<cassert>

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
		if (m_WeakReferenceFlag)
		{
			m_WeakReferenceFlag->Set(true);
			m_WeakReferenceFlag->Release();
		}
	}



	std::string BindRequest::GetMethod() const
	{
		return m_Request.method;
	}



	std::string BindRequest::GetTarget() const
	{
		return m_Request.target;
	}



	int BindRequest::AddRef()
	{
		return ++m_ReferencesCount;
	}



	int BindRequest::Release()
	{
		// TODO : this seems so ugly. Even if this is the way to be done, there must be a way to either make this better
		// or to avoid copy paste between many types.
		if (--m_ReferencesCount == 0)
			delete this;

		return m_ReferencesCount;
	}



	asILockableSharedBool *BindRequest::GetWeakRefFlag()
	{
		if (m_WeakReferenceFlag == nullptr)
			m_WeakReferenceFlag = asCreateLockableSharedBool();

		return m_WeakReferenceFlag;
	}



	void BindRequest::RegisterIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Register object.
		r = scriptingService.scriptEngine->RegisterObjectType("Request", 0, asOBJ_REF); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Request", asBEHAVE_ADDREF, "void f()", asMETHOD(BindRequest, AddRef), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Request", asBEHAVE_RELEASE, "void f()", asMETHOD(BindRequest, Release), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Request", asBEHAVE_GET_WEAKREF_FLAG, "int &f()", asMETHOD(BindRequest, GetWeakRefFlag), asCALL_THISCALL); assert(r >= 0);

		// Properties
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_method() const property", asMETHOD(BindRequest, GetMethod), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Request", "string get_target() const property", asMETHOD(BindRequest, GetTarget), asCALL_THISCALL); assert(r >= 0);
	}
}
