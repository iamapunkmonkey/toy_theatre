#pragma once

#include "Input.h"

namespace lunk {
	class SDLInput : public Input {
	public:
		SDLInput();

		Vec2 getMousePosition() override;

		bool keyWasPressed(Key key) override;

		bool keyWasReleased(Key key) override;

		bool keyIsDown(Key key) override;

		bool mouseButtonIsDown(MouseButton button) override;

		bool windowClosedRequest() override;

		void update() override;

	private:
		struct Implementation;
		Implementation *impl;
	};
}