#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace craco {
	class console_animation {
	public:
		typedef std::vector<std::string> frame;

		console_animation(std::ostream& os)
			: os_(os)
			, started_(false) {}

		void cancel(const std::string& message = "") {
			os_ << message;
		}

		void set_frame(const frame& frame) {
			if (started_) {
				clear_frame();
			}
			else {
				started_ = true;
			}

			write_frame(frame);
		}


	private:

		template <typename T>
		T clamp(T v, T min, T max) {
			if (v < min) return min;
			if (v > max) return max;
			return v;
		}

		void clear_frame() {
			os_ << std::string(last_frame_length_, '\r');
		}

		void write_frame(const frame& frame) {
			auto line_width = calculate_line_width(frame);
			for (const auto& line : frame) {
				os_ << line;
				if (line.size() < line_width) {
					auto fill_chars = line_width - line.size();
					os_ << std::string(fill_chars, ' ');
				}
				os_ << "\n";
			}
			os_ << std::flush;

			last_frame_length_ = (line_width + 1) * frame.size();
		}

		size_t calculate_line_width(const frame& frame) {
			auto max_element = std::max_element(frame.begin(), frame.end());
			if (max_element == frame.end()) {
				return 0;
			}
			return max_element->size();
		}

		std::ostream& os_;
		bool started_;
		size_t last_frame_length_;
	};
}