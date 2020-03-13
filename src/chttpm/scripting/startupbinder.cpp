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
			BindHttpStatusCode::RegisterIntoScriptingService(scriptingService);
			BindQueryParameters::RegisterIntoScriptingService(scriptingService);
			BindRequest::RegisterIntoScriptingService(scriptingService);
			BindResponse::RegisterIntoScriptingService(scriptingService);
			BindMessageLoggerKeys::RegisterIntoScriptingService(scriptingService);
			BindBuilderLoggerKeys::RegisterIntoScriptingService(scriptingService);
			BindLogger::RegisterIntoScriptingService(scriptingService);
		}
	}
}
