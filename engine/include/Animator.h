#pragma once

#include <string>

#include "Texture.h"
#include "Renderable.h"

#include "List.h"
#include "Rect2.h"
#include "Updateable.h"

using namespace std;

namespace lunk {
	class Renderer;

	class AnimationNode {
	public:
		Rect2 *src;

		double time;

		AnimationNode(Rect2 *src) {
			this->src = src;
		}
	};

	class Animation {
	public:
		List<AnimationNode *> *nodes;
		int frame;

		Animation() {
			nodes = new List<AnimationNode *>();
			frame = 0;
		}
	};

	class Animator {
	public:
		Animator(Texture *texture) :
				texture(texture) {
			animation = new Animation();
			frame = 0;

		}

		void addAnimationNode(Rect2 *src);

		void render(Renderer *, Vec2);

		void update(double delta);

	private:
		Texture *texture;
		Animation *animation;
		int frame;
		double totalDelta;
	};
}