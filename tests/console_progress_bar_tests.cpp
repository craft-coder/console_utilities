#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <functional>
#include "console_progress_bar.h"

using namespace mcf;

TEST(progress_bar, default_usage) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.5);

	auto expected = "|##########          |";

	ASSERT_TRUE(expected == s.str());
}

TEST(progress_bar, change_values) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.5);
	cpb.set(0.1);

	auto expected = "|##                  |";

	ASSERT_TRUE(expected == s.str());
}

TEST(progress_bar, negative_value) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(-0.3);

	auto expected = "|                    |";

	ASSERT_TRUE(expected == s.str());
}

TEST(progress_bar, greater_than_one) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(1.3);

	auto expected = "|####################|";

	ASSERT_TRUE(expected == s.str());
}

TEST(progress_bar, finished_after_one) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(1.0);
	cpb.set(0.3);

	auto expected = "|####################|\n";

	ASSERT_TRUE(expected == s.str());
}


TEST(progress_bar, cancel) {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.1);
	cpb.cancel(" Canceled");

	auto expected = "|##                  | Canceled\n";
	auto actual = s.str();

	ASSERT_TRUE(expected == actual);
}

TEST(progress_bar, changed) {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_filled_char('!');
	cpb.set_blank_char('-');

	cpb.set(0.1);

	auto expected = "|!!------------------|";
	
	ASSERT_TRUE(expected == s.str());
}

TEST(progress_bar, start_end_changed) {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_bar_start("Test _/|");
	cpb.set_bar_end("|\\_ Done");

	cpb.set(0.1);

	auto expected = "Test _/|##                  |\\_ Done";

	ASSERT_TRUE(expected == s.str());
}



