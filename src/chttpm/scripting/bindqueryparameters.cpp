#include"bindqueryparameters.h"



namespace chttpm
{
	BindQueryParameters::BindQueryParameters(const QueryParameters& queryParameters)
		: BindReference(), m_QueryParameters(queryParameters)
	{
	}



	void BindQueryParameters::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("QueryParameters", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("QueryParameters", scriptingService);
	}



	void BindQueryParameters::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("QueryParameters", "string GetValue(string) const", asMETHODPR(QueryParameters, GetValue, (const std::string) const, std::string), asCALL_THISCALL, 0, asOFFSET(BindQueryParameters, m_QueryParameters)); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("QueryParameters", "string GetValue(int) const", asMETHODPR(QueryParameters, GetValue, (int) const, std::string), asCALL_THISCALL, 0, asOFFSET(BindQueryParameters, m_QueryParameters)); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("QueryParameters", "int size() const", asMETHOD(QueryParameters, size), asCALL_THISCALL, 0, asOFFSET(BindQueryParameters, m_QueryParameters)); assert(r >= 0);

		// Operators overloads
		r = scriptingService.scriptEngine->RegisterObjectMethod("QueryParameters", "string get_opIndex(string) const property", asMETHODPR(QueryParameters, GetValue, (const std::string)const, std::string), asCALL_THISCALL, 0, asOFFSET(BindQueryParameters, m_QueryParameters)); assert(r >= 0);
	}
}