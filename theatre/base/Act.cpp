#include "Act.h"

void Act::update(double delta, int frame) {
	for(auto &scene : scenes)
		scene->update(delta, frame);
}

void Act::render(Renderer *renderer) {
	for(auto &scene : scenes)
		scene->render(renderer);
}

void Act::registerScene(Scene *scene) {
	this->scenes.push_back(scene);
}

Show* Act::getShow(){
	return show;
}