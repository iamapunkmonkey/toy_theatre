#pragma once

#include "Action.h"

class MovementAction : public Action {
public:
	MovementAction() : Action(ActionType::MOVEMENT) { }
};