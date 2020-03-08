#pragma once

#include<cassert>

#include<angelscript.h>

#include"../scriptingservice.h"



namespace chttpm
{
	template <typename T>
	class BindReference
	{
	protected:
		BindReference()
		{
		}

		virtual ~BindReference()
		{
			if (m_WeakReferenceFlag)
			{
				m_WeakReferenceFlag->Set(true);
				m_WeakReferenceFlag->Release();
			}
		}




		static void RegisterIntoScriptingService(const char* typeName, ScriptingService& scriptingService)
		{
			int r;

			// Register object.
			r = scriptingService.scriptEngine->RegisterObjectBehaviour(typeName, asBEHAVE_ADDREF, "void f()", asMETHOD(T, AddRef), asCALL_THISCALL); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterObjectBehaviour(typeName, asBEHAVE_RELEASE, "void f()", asMETHOD(T, Release), asCALL_THISCALL); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterObjectBehaviour(typeName, asBEHAVE_GET_WEAKREF_FLAG, "int &f()", asMETHOD(T, GetWeakRefFlag), asCALL_THISCALL); assert(r >= 0);
		}



	protected:
		int AddRef()
		{
			return ++m_ReferencesCount;
		}



		int Release()
		{
			if (--m_ReferencesCount == 0)
				delete this;

			return m_ReferencesCount;
		}



		asILockableSharedBool *GetWeakRefFlag()
		{
			if (m_WeakReferenceFlag == nullptr)
				m_WeakReferenceFlag = asCreateLockableSharedBool();

			return m_WeakReferenceFlag;
		}



	private:
		int m_ReferencesCount = 1;
		asILockableSharedBool *m_WeakReferenceFlag = nullptr;
	};
}
