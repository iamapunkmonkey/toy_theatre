#pragma once

namespace lunk {
	class Updateable {
	public:
		virtual void update(double timeDelta, int i) = 0;

		virtual ~Updateable() {

		}
	};
}