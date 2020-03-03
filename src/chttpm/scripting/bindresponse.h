#pragma once

#include<string>



class asILockableSharedBool;

namespace chttpm
{
	struct Response;
	class ScriptingService;


	// Binds a chttpm::Response to the Angel Script engine, with needed extra
	// behaviors.
	class BindResponse final
	{
	public:
		explicit BindResponse(Response& response);
		~BindResponse();

		std::string GetBody() const;
		void SetBody(std::string& body);

		// Angel Script
		int AddRef();
		int Release();
		asILockableSharedBool *GetWeakRefFlag();

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		Response& m_Response;

		// Angel Script
		int m_ReferencesCount = 1;
		asILockableSharedBool *m_WeakReferenceFlag = nullptr;
	};
}