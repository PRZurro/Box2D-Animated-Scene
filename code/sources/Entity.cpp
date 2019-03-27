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
	b2Joint * prz::Entity::join(const PString & bodyNameA, const PString & bodyNameB, bool collide, bool revolute)
	{
		if (bodyNameA != bodyNameB) // If the bodies are not the same
		{
			if (exists_body(bodyNameA) && exists_body(bodyNameB)) // Check if both exist
			{
				b2JointDef * jointDef; // Depending if is revolute joint or not we need a pointer to the created joint definition

				if (revolute)
				{
					jointDef = new b2RevoluteJointDef();
				}
				else
				{
					jointDef = new b2JointDef();
				}

				// Apply the basics of the joint definition
				jointDef->bodyA = bodies_[bodyNameA];
				jointDef->bodyB = bodies_[bodyNameB];
				jointDef->collideConnected = collide;

				joints_.push_back(scene_.create_joint(jointDef));

				if (revolute)
				{
					revoluteJoints_.push_back((b2RevoluteJoint*)joints_.back());
				}
				
				return revoluteJoints_.back(); // Return the joint for external desired modifications
			}
		}

		return nullptr;
	}
}

