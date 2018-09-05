#include <iostream>
#include <thread>
#include <chrono>
#include "console_progress_bar.h"

using namespace craco;

int main() {

	console_progress_bar cpb(std::cout);

	for (auto i = 0; i <= 100; i++) {
		cpb.set(i*0.01);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return EXIT_SUCCESS;
}