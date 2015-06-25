#include "Scene.h"

void Scene::update(double delta) {
	for (auto &worldObject : worldObjects) {
		worldObject->update(delta);
	}
}

void Scene::render(Renderer *renderer) {
	for (auto &worldObject : worldObjects) {
		worldObject->render(renderer);
	}
	act
}

void Scene::registerObject(WorldObject *obj)  {
	worldObjects.push_back(obj);
}

Act* Scene::getAct() {
	return act;
}