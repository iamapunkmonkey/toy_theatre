#pragma once

#include <cmath>
#include <random>

namespace lunk {
	class Random {
	public:
		Random() {
			std::random_device rd;
			randomEngine = std::default_random_engine(rd());
			uniformIntDistribution = std::uniform_int_distribution<int>(0, 0x00ffffff);
		}

	private:
		std::default_random_engine randomEngine;
		std::uniform_int_distribution<int> uniformIntDistribution;
	};
}