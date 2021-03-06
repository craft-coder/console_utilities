#pragma once
#include <iostream>
#include <string>

namespace craco {
	class console_progress_bar {
	public:
		console_progress_bar(std::ostream& os, unsigned int width = 20)
			: os_(os)
			, width_(width)
			, filled_char('#')
			, blank_char(' ')
			, bar_start_("|")
			, bar_end_("|")
			, started_(false)
			, finished_(false) {}

		void set_filled_char(char c) {
			filled_char = c;
		}

		void set_blank_char(char c) {
			blank_char = c;
		}

		void set_bar_start(const std::string& bar_start) {
			bar_start_ = bar_start;
		}

		void set_bar_end(const std::string& bar_end) {
			bar_end_ = bar_end;
		}

		void cancel(const std::string& message = "") {
			finished_ = true;
			os_ << message;
		}

		void set_width(unsigned int width) {
			width_ = clamp(width, 0u, 1000u);
		}

		void set(double percentage) {
			if (finished_) return;

			if (started_) {
				clear_line();
			}
			else {
				started_ = true;
			}

			if (percentage >= 1.0) {
				percentage = 1.0;
				finished_ = true;
			}

			percentage = clamp(percentage, 0.0, 1.0);
			write_line(percentage);
		}


	private:

		template <typename T>
		T clamp(T v, T min, T max) {
			if (v < min) return min;
			if (v > max) return max;
			return v;
		}

		void clear_line() {
			os_ << std::string(last_line_length_, '\r');
		}

		void write_line(double percentage) {
			auto num_filled = static_cast<int>(percentage*width_);
			auto num_blank = width_ - num_filled;
			auto text = bar_start_ + std::string(num_filled, filled_char) + std::string(num_blank, blank_char) + bar_end_;
			os_ << text << std::flush;
			last_line_length_ = text.size();
		}

		std::ostream& os_;
		unsigned int width_;
		char filled_char;
		char blank_char;
		std::string bar_start_;
		std::string bar_end_;
		bool started_;
		bool finished_;
		size_t last_line_length_;
	};
}