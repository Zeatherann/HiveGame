#ifndef COLLISION_INFO_HPP
#define COLLISION_INFO_HPP

struct CollisionInfo {
	shared_ptr<Object> First;
	shared_ptr<Object> Second;
};

#endif