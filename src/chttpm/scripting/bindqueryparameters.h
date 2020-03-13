#pragma once

#include"helper/bindreference.h"

#include"../queryparameters.h"



namespace chttpm
{
	class ScriptingService;



	class BindQueryParameters : public BindReference<BindQueryParameters>
	{
	public:
		explicit BindQueryParameters(const QueryParameters& queryParameters);

		static void RegisterTypeIntoScriptingService(ScriptingService& scriptingService);
		static void RegisterOperationsIntoScriptingService(ScriptingService& scriptingService);



	private:
		const QueryParameters m_QueryParameters;
	};
}