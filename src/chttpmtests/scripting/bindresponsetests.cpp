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



	TEST_CASE("Response bindings", "[Response]")
	{
		ScriptingService scriptingService{};
		StartupBinder::BindAll(scriptingService);

		Request request{};
		Response response{};

		SECTION("Set a Status Code value [1]")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.statusCode = 200;"
				"}"
			);

			AssertNotEqual(200, response.statusCode, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(200, response.statusCode, "after script call");
		}

		SECTION("Set a Status Code value [2]")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.statusCode = 404;"
				"}"
			);

			AssertNotEqual(404, response.statusCode, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(404, response.statusCode, "after script call");
		}

		SECTION("Set a Body value [1]")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = \"talihoo\";"
				"}"
			);

			AssertNotEqual("talihoo", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("talihoo", response.body, "after script call");
		}

		SECTION("Set a Body value [2]")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    response.body = \"a bit more elaborated text\";"
				"}"
			);

			AssertNotEqual("a bit more elaborated text", response.body, "before script call");
			scriptingService.ProcessRequest("module", request, response);
			AssertEqual("a bit more elaborated text", response.body, "after script call");
		}
	}
}
