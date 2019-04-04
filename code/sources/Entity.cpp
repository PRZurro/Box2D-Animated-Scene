#include "Entity.hpp"
#include "Scene.hpp"

namespace prz
{
	b2Body * Entity::add_body(const b2BodyDef * bodyDef, const PString & bodyName, const b2BodyType & bodyType)
	{
		bodies_[bodyName] = scene_.create_body(bodyDef);
		bodies_[bodyName]->SetType(bodyType);
		bodies_[bodyName]->SetTransform(startTransform_.p,startTransform_.q.GetAngle());

		return bodies_[bodyName];
	}
	b2Joint * Entity::add_joint(const b2JointDef * jointDef)
	{
		joints_.push_back(scene_.create_joint(jointDef));
		return joints_.back();
	}
}
