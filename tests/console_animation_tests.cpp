#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include "tests_common.h"
#include "console_animation.h"

using namespace craco;

TEST(animation, default_usage) {
	std::stringstream s;
	console_animation ca(s);

	auto l1 = std::string("###############");
	auto l2 = std::string("# Hello World #");
	auto l3 = l1;
	auto frame = { l1, l2, l3 };

	ca.set_frame(frame);

	auto expected = l1 + "\n" + l2 + "\n" + l3 + "\n";
	ASSERT_BUFFER(expected.c_str(), s);
}