#pragma once

#include "Rect2.h"

namespace lunk {
	struct CollisionShape {
		enum class Type : uint8_t {
			CIRCLE,
			RECT
		};

		Type type;

		union {
			struct {
				double radius;
			} circle;

			struct {
				double width;
				double height;
			} rect;
		};
	};

	struct ShapeTransformation {
		Vec2 translation;
	};

	class PhysicsEngine {
	public:
		bool intersection(const CollisionShape &lhs,
						  const ShapeTransformation &lhsTransform,
						  const CollisionShape &rhs,
						  const ShapeTransformation &rhsTransform);

		CollisionShape *createCircleShape(double radius);

		CollisionShape *createRectShape(double width, double height);

		void releaseShape(CollisionShape *shape);
	};
}