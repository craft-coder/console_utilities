#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include "console_progress_bar.h"

using namespace mcf;

std::string evaluate(const std::stringstream& s) {
	auto result = s.str();
	size_t pos_found;
	while ((pos_found = result.find('\r')) != std::string::npos) {
		result.erase(pos_found - 1, 2);
	}
	return result;
}

void ASSERT_BUFFER(const char* expected, const std::stringstream& s) {
	auto evaluated = evaluate(s);
	ASSERT_STREQ(expected, evaluated.c_str());
}

TEST(progress_bar, default_usage) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.5);

	auto expected = "|##########          |";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, change_values) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.5);
	cpb.set(0.1);

	auto expected = "|##                  |";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, negative_value) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(-0.3);

	auto expected = "|                    |";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, greater_than_one) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(1.3);

	auto expected = "|####################|";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, finished_after_one) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(1.0);
	cpb.set(0.3);

	auto expected = "|####################|";
	ASSERT_BUFFER(expected, s);
}


TEST(progress_bar, cancel) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.1);
	cpb.cancel(" Canceled");

	auto expected = "|##                  | Canceled";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, changed) {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_filled_char('!');
	cpb.set_blank_char('-');

	cpb.set(0.1);

	auto expected = "|!!------------------|";
	ASSERT_BUFFER(expected, s);
}

TEST(progress_bar, start_end_changed) {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_bar_start("Test _/|");
	cpb.set_bar_end("|\\_ Done");

	cpb.set(0.1);

	auto expected = "Test _/|##                  |\\_ Done";
	ASSERT_BUFFER(expected, s);
}



