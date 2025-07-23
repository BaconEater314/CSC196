#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"

#include <memory>
#include <string>

namespace bacon {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{ 0, 0 };
		float damping{ 0.2f };

		Transform transform;
		class Scene* scene{ nullptr };

	public:
		Actor() = default;
		Actor(Transform transform, std::shared_ptr<class Model> model) :
			transform { transform },
			m_model { model }
		{ }

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& getTransform() { return transform; }

	protected:
		std::shared_ptr<Model> m_model;

	private:
	};
}