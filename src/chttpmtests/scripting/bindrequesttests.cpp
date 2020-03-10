#include"../catch.hpp"
#include"../assertions.h"

#include<request.h>
#include<response.h>

#include<scripting/scriptingservice.h>
#include<scripting/startupbinder.h>
#include<scripting/bindrequest.h>
#include<scripting/bindresponse.h>



namespace LogTests
{
	using namespace chttpm;



	TEST_CASE("Request bindings", "[Request]")
	{
		ScriptingService scriptingService{};
		StartupBinder::BindAll(scriptingService);

		Request request{};
		Response response{};

		SECTION("Set a method value [1]")
		{
			request.method = "GET";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.method;"
				"}"
			);

			AssertNotEqual("GET", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("GET", response.body, "after script call");
		}

		SECTION("Set a method value [2]")
		{
			request.method = "POST";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.method;"
				"}"
			);

			AssertNotEqual("POST", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("POST", response.body, "after script call");
		}

		SECTION("Set a target value [1]")
		{
			request.target = "/v1/someresource";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.target;"
				"}"
			);

			AssertNotEqual("/v1/someresource", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("/v1/someresource", response.body, "after script call");
		}

		SECTION("Set a target value [2]")
		{
			request.target = "resource";

			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = request.target;"
				"}"
			);

			AssertNotEqual("resource", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("resource", response.body, "after script call");
		}
	}
}
