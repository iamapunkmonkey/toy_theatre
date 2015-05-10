#pragma once

#include "Engine.h"

namespace lunk {
	class FPSCounter {
	public:
		FPSCounter(const lunk::Engine *game)
				: engine(game),
				  lastFrameCount(engine->getFrameCount()) {

		}

		double seconds() {
			return timer.seconds();
		}

		void restart() {
			timer.restart();
			lastFrameCount = engine->getFrameCount();
		}

		double getFPS() {
			return (double) (engine->getFrameCount() - lastFrameCount) / timer.seconds();
		}

	private:
		const lunk::Engine *engine;
		lunk::LunkTimer timer;
		int lastFrameCount = 0;

	};
}