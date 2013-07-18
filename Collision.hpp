#ifndef COLLISION_HPP
#define COLLISION_HPP

struct Collision {
	shared_ptr<Object> First;
	shared_ptr<Object> Second;
};

bool ObjectsCollide(const shared_ptr<Object>& o1, const shared_ptr<Object>& o2);
vector<Collision>&& SearchForCollisions(vector<shared_ptr<Object>>& objects);

#endif