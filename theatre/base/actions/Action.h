#pragma once

#include <vector>
#include <ctime>

using namespace std;

class Action {
public:
	Action(ActionType);

	enum ActionType {
		MOVEMENT
	};


private:
	ActionType type;
	clock_t t;
};

