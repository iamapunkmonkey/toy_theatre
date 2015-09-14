#include "Scene.h"

void Scene::update(double delta, int frame) {
	for (auto &worldObject : worldObjects) {
		worldObject->update(delta, frame);
	}
}

void Scene::render(Renderer *renderer) {
	for (auto &worldObject : worldObjects) {
		worldObject->render(renderer);
	}
}

void Scene::registerObject(WorldObject *obj)  {
	worldObjects.push_back(obj);
}

Act* Scene::getAct() {
	return act;
}