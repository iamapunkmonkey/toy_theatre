#pragma once

namespace lunk {
	class Renderer;

	class Renderable {
	public:
		virtual void render(Renderer *renderer) = 0;

		virtual ~Renderable() {

		}
	};
}