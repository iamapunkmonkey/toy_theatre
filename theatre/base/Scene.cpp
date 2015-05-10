#include "Show.h"

void Scene::update(double delta) { }

void Scene::render(Renderer *renderer) { }

void Scene::registerObject(WorldObject *obj)  {
	worldObjects.push_back(obj);
}

Act* Scene::getAct() {
	return act;
}