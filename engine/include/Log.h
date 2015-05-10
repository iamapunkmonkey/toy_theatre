#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
#include <string.h>
#include <time.h>

//__FILE__, __LINE__

#define DEBUG() logger("DEBUG", __FILE__, __LINE__)
#define INFO() logger("INFO", __FILE__, __LINE__)
#define ERROR() logger("ERROR", __FILE__, __LINE__)
#define WARNING() logger("WARNING", __FILE__, __LINE__)

namespace lunk {
	class Log {
	public:
		Log() {

		}

		static std::ostream &logger(const std::string &level, const std::string &file, const long &line) {
			return prepareOutputStream(level, file, line);
		}

	private:
		static std::ostream &prepareOutputStream(const std::string &level, const std::string &file, const long &line) {
			char timestamp[10];

			memset(timestamp, 0, sizeof(timestamp));

			time_t now = time(nullptr);
			tm tm = *localtime(&now);

			strftime(timestamp, sizeof(timestamp), "%H:%M:%S", &tm);

			return std::cout << timestamp << " " << level << " [" << file << " - " << line << "] ";
		}
	};
}