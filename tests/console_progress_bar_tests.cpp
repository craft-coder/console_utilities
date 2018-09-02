#include <iostream>
#include <sstream>
#include <functional>
#include "console_progress_bar.h"

using namespace mcf;

template <typename T1, typename T2>
bool check(T1 t1, T2 t2, const char* function_name) {
	if (t1 != t2) {
		std::cerr << "Test " << function_name << " failed\n";
		std::cerr << "Value " << t1 << " unequal " << t2 << "\n";
		return false;
	}
	return true;
}

bool test_default_usage() {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.5);

	auto expected = "|##########          |";
	auto actual = s.str();

	return check(expected, actual, __FUNCTION__);
}

bool test_cancel() {
	std::stringstream s;
	console_progress_bar cpb(s);

	cpb.set(0.1);
	cpb.cancel(" Canceled");

	auto expected = "|##                  | Canceled\n";
	auto actual = s.str();

	return check(expected, actual, __FUNCTION__);
}

bool test_char_changed() {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_filled_char('!');
	cpb.set_blank_char('-');

	cpb.set(0.1);

	auto expected = "|!!------------------|";
	auto actual = s.str();

	return check(expected, actual, __FUNCTION__);
}

bool test_start_end_changed() {
	std::stringstream s;
	console_progress_bar cpb(s);
	cpb.set_bar_start("Test _/|");
	cpb.set_bar_end("|\\_ Done");

	cpb.set(0.1);

	auto expected = "Test _/|##                  |\\_ Done";
	auto actual = s.str();

	return check(expected, actual, __FUNCTION__);
}



int main() {
	auto success = test_default_usage();
	success &= test_cancel();
	success &= test_char_changed();
	success &= test_start_end_changed();

	if (success) {
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}