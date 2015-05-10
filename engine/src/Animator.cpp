#include "Animator.h"
#include "Renderer.h"
#include <iostream>

void lunk::Animator::addAnimationNode(Rect2 *src) {
	animation->nodes->addNode(new AnimationNode(src));
}

void lunk::Animator::render(Renderer *renderer, Vec2 pos) {
	const Rect2 *s = animation->nodes->get(frame)->src;
	renderer->drawTexture(texture, pos, s);
}

void lunk::Animator::update(double delta) {

	totalDelta += delta;
	if (totalDelta < (1.0 / 15.0)) return;


	if (frame++ >= animation->nodes->count() - 1)
		frame = 0;

	totalDelta = 0;
}