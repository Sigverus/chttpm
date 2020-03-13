#pragma once

#include<string>

#include"helper/bindreference.h"



namespace chttpm
{
	class BindQueryParameters;
	struct Request;
	class ScriptingService;


	// Binds a chttpm::Request to the Angel Script engine, with needed extra
	// behaviors.
	class BindRequest final : public BindReference<BindRequest>
	{
	public:
		explicit BindRequest(const Request& request);

		std::string GetMethod() const;
		std::string GetTarget() const;
		const BindQueryParameters* GetQueryParameters() const;

		static void RegisterTypeIntoScriptingService(ScriptingService& scriptingService);
		static void RegisterOperationsIntoScriptingService(ScriptingService& scriptingService);



	private:
		const Request& m_Request;
	};
}

