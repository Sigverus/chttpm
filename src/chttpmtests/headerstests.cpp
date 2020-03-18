#include"catch.hpp"
#include"assertions.h"

#include<headers.h>



namespace HeadersTests
{
	using namespace chttpm;

	TEST_CASE("Header::Header(const char*, const char*)", "[Header]")
	{
		Header header{ "key", "value" };
		AssertEqual("key", header.key, "header key");
		AssertEqual("value", header.value, "header value");
	}



	TEST_CASE("Header::GetValue(const char*)", "[Headers]")
	{
		Headers headers{};

		SECTION("Not registered key on empty headers returns empty string")
		{
			AssertEqual("", headers.GetValue("someKey"), "not registered key");
		}

		headers.Set("someKey", "someValue");

		SECTION("Not registered key on not empty headers returns empty string")
		{
			AssertEqual("", headers.GetValue("otherKey"), "not registered key");
		}

		SECTION("Getting value")
		{
			AssertEqual("someValue", headers.GetValue("someKey"), "registered key");
		}
	}



	TEST_CASE("Headers::GetValue(int)", "[Headers]")
	{
		Headers headers{};

		SECTION("Not registered index on empty headers returns empty string")
		{
			AssertEqual("", headers.GetValue(0), "0 index on empty parameters");
			AssertEqual("", headers.GetValue(1), "some index out of bounds");
		}

		headers.Set("someKey", "someValue");

		SECTION("Not registered index on not empty headers returns empty string")
		{
			AssertEqual("", headers.GetValue(1), "some index out of bounds");
		}

		SECTION("Negative index returns empty")
		{
			AssertEqual("", headers.GetValue(-1), "negative index");
		}

		SECTION("Getting value")
		{
			AssertEqual("someValue", headers.GetValue("someKey"), "registered key");
		}
	}



	TEST_CASE("Headers::size()", "[Headers]")
	{
		Headers headers{};
		AssertEqual(0, headers.size(), "empty");

		headers.Set("someKey", "someValue");
		AssertEqual(1, headers.size(), "after one insertion");
	}



	TEST_CASE("Headers::Set(const char*, const char*", "[Headers]")
	{
		Headers headers{};

		headers.Set("someKey", "someValue");
		AssertEqual(1, headers.size(), "size after adding someKey");
		AssertEqual("someValue", headers.GetValue("someKey"), "retrieving someValue");

		headers.Set("someOtherKey", "someOtherValue");
		AssertEqual(2, headers.size(), "size after adding someOtherKey");
		AssertEqual("someOtherValue", headers.GetValue("someOtherKey"), "retrieving some other value");

		headers.Set("someKey", "someNewValue");
		AssertEqual(2, headers.size(), "size after setting same key again should not change");
		AssertEqual("someNewValue", headers.GetValue("someKey"), "someKey's value has been re-set");
	}



	TEST_CASE("Header::GetHeader")
	{
		Headers headers{};
		headers.Set("someKey", "someValue");

		auto header = headers.GetHeader(-1);
		AssertEqual("", header.key, "Negative index key");
		AssertEqual("", header.value, "Negative index value");

		header = headers.GetHeader(1);
		AssertEqual("", header.key, "Too high index key");
		AssertEqual("", header.value, "Too high index value");

		header = headers.GetHeader(0);
		AssertEqual("someKey", header.key, "found index key");
		AssertEqual("someValue", header.value, "found index value");
	}
}
