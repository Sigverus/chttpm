#pragma once

#include<string>



class asILockableSharedBool;

namespace chttpm
{
	struct Request;
	class ScriptingService;

	// Binds a chttpm::Request for the Angel Script engine, with needed extra
	// behaviors.
	class BindRequest final
	{
	public:
		BindRequest(const Request& request);
		~BindRequest();

		std::string GetMethod() const;
		std::string GetTarget() const;

		// Angel Script
		int AddRef();
		int Release();
		asILockableSharedBool *GetWeakRefFlag();

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		const Request& m_Request;

		// Angel Script
		int m_ReferencesCount = 1;
		asILockableSharedBool *m_WeakReferenceFlag = nullptr;
	};
}

