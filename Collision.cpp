#include "Collision.hpp"

bool ObjectsCollide(const shared_ptr<Object>& o1, const shared_ptr<Object>& o2) {
	// To be implemented using Separating Axis Test.
	// Mode: Pixel perfect collision.
	return false;
}

vector<Collision>&& SearchForCollisions(vector<shared_ptr<Object>>& objects) {
	vector<Collision> collisions;
	
	for (const auto& object1 : objects) {
		for (const auto& object2 : objects) {

			if (object1 == object2) {
				continue;
			} else {
				auto copy_finder = [object1, object2](Collision& node) -> bool {
					return (object1 == node.First && object2 == node.Second) ||
						   (object2 == node.First && object1 == node.Second);
				};

				auto seeked_copy = std::find_if(collisions.begin(), collisions.end(), copy_finder);

				if (seeked_copy == collisions.end()) {
					if (ObjectsCollide(object1, object2)) {
						collisions.emplace_back({object1, object2});
					}
				}
			}
		}
	}

	return std::move(collisions);
}