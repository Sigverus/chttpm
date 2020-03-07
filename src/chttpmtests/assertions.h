#pragma once

#include<string>


void AssertTrue(bool condition, const char* description);
void AssertFalse(bool condition, const char* description);

void AssertEqual(const std::string& expected, const std::string& received, const char* description);
