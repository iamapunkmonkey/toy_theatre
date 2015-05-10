#pragma once

#include <unordered_map>

#include "Updateable.h"
#include "Transform.h"

namespace lunk {
	class Renderable;

	class Transform;

	class Entity : public Updateable {
	public:
		Renderable *getRenderComponent() {
			return renderComponent;
		}

		void setRenderComponent(Renderable *&&renderComponent) {
			std::swap(this->renderComponent, renderComponent);
		}

		Transform &getTransformComponent() {
			return transform;
		}

	private:
		Transform transform;
		Renderable *renderComponent;
	};
}