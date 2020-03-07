#include"../catch.hpp"
#include"../assertions.h"

#include<log/log.h>



namespace LogTests
{
	using namespace chttpm;

	TEST_CASE("Test logger building and output", "[Log]")
	{
		std::string output;
		OutputLogFunction = [&](const std::string out) { output = out; };

		Logger logger{};

		SECTION("Simple output")
		{
			logger.Info().Msg("info message");
			AssertEqual(R"({"Msg":"info message"})", output, "information output");
		}

		SECTION("Adding information on message does not mutate logger")
		{
			logger.Info().Str("strkey", "strvalue").Msg("enriched string information");
			AssertEqual(R"({"strkey":"strvalue","Msg":"enriched string information"})", output, "str information output");

			logger.Info().Msg("logger should not mutate after string enriched information");
			AssertEqual(R"({"Msg":"logger should not mutate after string enriched information"})", output, "unmodified str information output");
		}

		auto mutatedLogger = logger.With().Str("mut_str_key", "mut_str_val").Logger();
		SECTION("Simple output after mutating into new logger")
		{
			logger.Info().Msg("old logger");
			AssertEqual(R"({"Msg":"old logger"})", output, "old logger was not mutated");

			mutatedLogger.Info().Msg("mutated logger");
			AssertEqual(R"({"mut_str_key":"mut_str_val","Msg":"mutated logger"})", output, "new logger has mutated values");

			mutatedLogger.Info().Str("another_key", "another_value").Msg("enriched new logger");
			AssertEqual(R"({"mut_str_key":"mut_str_val","another_key":"another_value","Msg":"enriched new logger"})", output, "enriched mutated logger");
		}
	}
}

