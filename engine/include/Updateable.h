#pragma once

namespace lunk {
	class Updateable {
	public:
		virtual void update(double timeDelta) = 0;

		virtual ~Updateable() {

		}
	};
}