#include"startupbinder.h"

#include"scriptingservice.h"

#include"bindhttpstatuscode.h"
#include"bindqueryparameters.h"
#include"bindrequest.h"
#include"bindresponse.h"
#include"log/bindlog.h"



namespace chttpm
{
	namespace StartupBinder
	{
		void BindAll(ScriptingService& scriptingService)
		{
			BindHttpStatusCode::RegisterTypeIntoScriptingService(scriptingService);
			BindQueryParameters::RegisterTypeIntoScriptingService(scriptingService);
			BindRequest::RegisterTypeIntoScriptingService(scriptingService);
			BindResponse::RegisterTypeIntoScriptingService(scriptingService);
			BindMessageLoggerKeys::RegisterTypeIntoScriptingService(scriptingService);
			BindBuilderLoggerKeys::RegisterTypeIntoScriptingService(scriptingService);
			BindLogger::RegisterTypeIntoScriptingService(scriptingService);

			BindQueryParameters::RegisterOperationsIntoScriptingService(scriptingService);
			BindRequest::RegisterOperationsIntoScriptingService(scriptingService);
			BindResponse::RegisterOperationsIntoScriptingService(scriptingService);
			BindMessageLoggerKeys::RegisterOperationsIntoScriptingService(scriptingService);
			BindBuilderLoggerKeys::RegisterOperationsIntoScriptingService(scriptingService);
			BindLogger::RegisterOperationsIntoScriptingService(scriptingService);
		}
	}
}
