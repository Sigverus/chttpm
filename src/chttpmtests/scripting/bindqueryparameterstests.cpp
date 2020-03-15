#include"../catch.hpp"
#include"../assertions.h"

#include<request.h>
#include<response.h>

#include<scripting/scriptingservice.h>
#include<scripting/startupbinder.h>
#include<scripting/bindqueryparameters.h>
#include<scripting/bindrequest.h>
#include<scripting/bindresponse.h>



namespace LogTests
{
	using namespace chttpm;



	TEST_CASE("QueryParameters binding", "[BindQueryParameters]")
	{
		ScriptingService scriptingService{};
		StartupBinder::BindAll(scriptingService);

		Request request{};
		Response response{};

		SECTION("Bindings on an empty query parameters")
		{
			request.method = "GET";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.queryParameters.GetValue(\"param\") + \"\\n\";"
				"    response.body += request.queryParameters.GetValue(0) + \"\\n\";"
				"    response.body += request.queryParameters[\"param\"] + \"\\n\";"
				// TODO : methods for casting from integer to string
				// "    response.body += request.queryParameters.size();"
				"}"
			);

			const std::string expected{
				"\n"
				"\n"
				"\n"
				// "0"
			};

			AssertNotEqual(expected, response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(expected, response.body, "after script call");
		}

		request.queryParameters.Add("fried", "potato");
		request.queryParameters.Add("star", "gate");
		request.queryParameters.Add("prime", "31");

		SECTION("Bindings on filled query parameters")
		{
			request.method = "GET";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.queryParameters.GetValue(\"fried\") + \"\\n\";"
				"    response.body += request.queryParameters.GetValue(1) + \"\\n\";"
				"    response.body += request.queryParameters[\"prime\"] + \"\\n\";"
				// TODO : methods for casting from integer to string
				// "    response.body += request.queryParameters.size();"
				"}"
			);

			const std::string expected{
				"potato\n"
				"gate\n"
				"31\n"
				// "3"
			};

			AssertNotEqual(expected, response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(expected, response.body, "after script call");
		}
	}
}
