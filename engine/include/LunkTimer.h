#pragma once

#include <stdint.h>
#include "../timer/timer.h"

namespace lunk {
	class LunkTimer {
	public:
		LunkTimer();

		void restart();

		double seconds();

	private:
		Timer timer;
	};
}