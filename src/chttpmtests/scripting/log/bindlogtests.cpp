#include"../../catch.hpp"
#include"../../assertions.h"

#include<request.h>
#include<response.h>
#include<log/log.h>

#include<scripting/scriptingservice.h>
#include<scripting/startupbinder.h>



namespace BindLogTests
{
	using namespace chttpm;



	TEST_CASE("Log bindings", "[Log]")
	{
		ScriptingService scriptingService{};
		StartupBinder::BindAll(scriptingService);

		Request request{};
		Response response{};

		std::string output;
		OutputLogFunction = [&](const std::string out) { output = out; };

		SECTION("Simple info message")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    logger.Info().Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"Msg":"info message"})", output, "log output");
		}

		SECTION("Info message enriched with string")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    logger.Info().Str(\"strkey\",\"strvalue\").Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"strkey":"strvalue","Msg":"info message"})", output, "log output");
		}

		SECTION("Info message from new logger built from a simple logger")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    Logger logger2 = logger.With().Logger();"
				"    logger2.Info().Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"Msg":"info message"})", output, "log output");
		}

		SECTION("Info message from new logger built from enriched logger")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    Logger logger2 = logger.With().Str(\"strkey\",\"strvalue\").Logger();"
				"    logger2.Info().Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"strkey":"strvalue","Msg":"info message"})", output, "log output");
		}

		SECTION("Info message from new enriched logger built from simple logger")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    Logger logger2 = logger.With().Logger();"
				"    logger2.Info().Str(\"key\",\"value\").Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"key":"value","Msg":"info message"})", output, "log output");
		}

		SECTION("Info message from new enriched logger built from enriched logger")
		{
			scriptingService.LoadModuleFromMemory(
				"module",
				"void ProcessRequest(const Request& request, Response& response) {"
				"    Logger logger;"
				"    Logger logger2 = logger.With().Str(\"k1\", \"v1\").Logger();"
				"    logger2.Info().Str(\"k2\", \"v2\").Msg(\"info message\");"
				"}"
			);

			scriptingService.ProcessRequest("module", request, response);
			AssertEqual(R"({"k1":"v1","k2":"v2","Msg":"info message"})", output, "log output");
		}
	}
}
