#include "LunkTimer.h"


namespace lunk {
	LunkTimer::LunkTimer() {
		timer.start();
	}


	double LunkTimer::seconds() {
		return timer.getElapsedTimeInSec();
	}

	void LunkTimer::restart() {
		timer.stop();
		timer.start();
	}

}