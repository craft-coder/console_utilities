#pragma once
#include <string>
#include <sstream>
#include "gtest/gtest.h"

inline std::string simple_evaluate(const std::stringstream& s) {
	auto result = s.str();
	size_t pos_found;
	while ((pos_found = result.find('\r')) != std::string::npos) {
		result.erase(pos_found - 1, 2);
	}
	return result;
}

inline void ASSERT_BUFFER(const char* expected, const std::stringstream& s) {
	auto evaluated = simple_evaluate(s);
	ASSERT_STREQ(expected, evaluated.c_str());
}