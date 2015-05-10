#include "Actor.h"

void Act::update(double delta) { }

void Act::render(Renderer *renderer) { }

void Act::registerScene(Scene *scene) {
	scenes.push_back(scene);
}

Show* Act::getShow(){
	return show;
}