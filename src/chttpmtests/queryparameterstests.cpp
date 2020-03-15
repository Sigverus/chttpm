#include"catch.hpp"
#include"assertions.h"

#include<queryparameters.h>



namespace LogTests
{
	using namespace chttpm;



	TEST_CASE("QueryParameters::GetValue(const std::string) failures", "[QueryParameters]")
	{
		QueryParameters queryParameters{};

		SECTION("Not registered key on empty parameters returns empty string")
		{
			AssertEqual("", queryParameters.GetValue("someKey"), "registered key");
		}

		SECTION("Not registered key on not empty parameters returns empty string")
		{
			queryParameters.Add("someKey", "someValue");
			AssertEqual("", queryParameters.GetValue("otherKey"), "registered key");
		}
	}



	TEST_CASE("QueryParameters::GetValue(int) failures", "[QueryParameters]")
	{
		QueryParameters queryParameters{};

		SECTION("Not registered index on empty parameters returns empty string")
		{
			AssertEqual("", queryParameters.GetValue(0), "0 index on empty parameters");
			AssertEqual("", queryParameters.GetValue(1), "some index on empty parameters");
		}

		queryParameters.Add("someKey", "someValue");

		SECTION("Not registered index on not empty parameters returns empty string")
		{
			AssertEqual("", queryParameters.GetValue(1), "some index on empty parameters");
		}

		SECTION("Negative index returns empty string")
		{
			AssertEqual("", queryParameters.GetValue(-1), "negative index");
		}
	}



	TEST_CASE("QueryParameters::size()", "[QueryParameters]")
	{
		QueryParameters queryParameters{};
		AssertEqual(0, queryParameters.size(), "empty");

		queryParameters.Add("someKey", "someValue");
		AssertEqual(1, queryParameters.size(), "after one insertion");
	}



	TEST_CASE("QueryParameters::Add(const std::string, const std::string)", "[QueryParameters]")
	{
		QueryParameters queryParameters{};

		queryParameters.Add("someKey", "someValue");
		AssertEqual(1, queryParameters.size(), "size after inserting someKey");
		AssertEqual("someValue", queryParameters.GetValue("someKey"), "fetching someKey by string");
		AssertEqual("someValue", queryParameters.GetValue(0), "fetching someKey by index");

		queryParameters.Add("otherKey", "otherValue");
		AssertEqual(2, queryParameters.size(), "size after inserting otherKey");
		AssertEqual("otherValue", queryParameters.GetValue("otherKey"), "fetching otherKey by string");
		AssertEqual("otherValue", queryParameters.GetValue(1), "fetching otherKey by index");

		// Repeated keys is undefined behavior on GetValue.
		queryParameters.Add("otherKey", "missingno");
		AssertEqual(3, queryParameters.size(), "size after inserting otherKey");
	}
}
