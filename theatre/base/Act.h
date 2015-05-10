#pragma once

#include "Scene.h"

using namespace lunk;

class Show;
class Scene;
class Act {
public:
	Act(Show* show) : show(show) {

	}

	void update(double timeDelta);

	void render(lunk::Renderer *renderer);

	void registerScene(Scene*);

	Show* getShow();

private:
	std::vector<Scene *> scenes;
	Show* show;
};