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
	auto frame = { l1, l2, l1 };

	ca.set_frame(frame);

	auto expected = l1 + "\n" + l2 + "\n" + l1 + "\n";
	ASSERT_BUFFER(expected.c_str(), s);
}

TEST(animation, simple_animation) {
	std::stringstream s;
	console_animation ca(s);

	auto l1 = std::string("###############");
	auto l2 = std::string("# Hello World #");
	auto frame1 = { l1, l2, l1 };
	auto frame2 = { l2, l1 };
	auto frame3 = { l1 };

	ca.set_frame(frame1);
	ca.set_frame(frame2);
	ca.set_frame(frame3);

	auto expected = l1 + "\n";;
	ASSERT_BUFFER(expected.c_str(), s);
}

TEST(animation, empty_frame) {
	std::stringstream s;
	console_animation ca(s);

	auto frame = { std::string() };
	ca.set_frame(frame);
	ASSERT_BUFFER("\n", s);
}