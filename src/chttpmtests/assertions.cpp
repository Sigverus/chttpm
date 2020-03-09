#include"assertions.h"

#include"catch.hpp"

#include<sstream>



void AssertTrue(bool condition, const char* description)
{
	std::ostringstream msg;
	msg << "[" << description << "]: expected true but received false.";

	INFO(msg.str());
	REQUIRE(condition);
}



void AssertFalse(bool condition, const char* description)
{
	std::ostringstream msg;
	msg << "[" << description << "]: expected false but received true.";

	INFO(msg.str());
	REQUIRE_FALSE(condition);
}



template <typename T>
void AssertEqualTemplate(const T& expected, const T& received, const char* description)
{
	std::ostringstream msg;
	msg << "[" << description << "]: expected " << expected
		<< " but received " << received << ".";

	INFO(msg.str());
	REQUIRE(expected == received);
}



void AssertEqual(const int expected, const int received, const char* description)
{
	AssertEqualTemplate(expected, received, description);
}



void AssertEqual(const std::string& expected, const std::string& received, const char* description)
{
	AssertEqualTemplate(expected, received, description);
}



template <typename T>
void AssertNotEqualTemplate(const T& expected, const T& received, const char* description)
{
	std::ostringstream msg;
	msg << "[" << description << "]: expected received value " << received
		<< " to be different from " << expected << ".";

	INFO(msg.str());
	REQUIRE(expected != received);
}



void AssertNotEqual(const int expected, const int received, const char* description)
{
	AssertNotEqualTemplate(expected, received, description);
}



void AssertNotEqual(const std::string& expected, const std::string& received, const char* description)
{
	AssertNotEqualTemplate(expected, received, description);
}

