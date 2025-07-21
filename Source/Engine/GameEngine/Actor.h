#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"

#include <memory>

namespace bacon {
	class Actor {
	public:
		Actor() = default;
		Actor(Transform transform, std::shared_ptr<class Model> model) :
			m_transform { transform },
			m_model { model }
		{ }

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& getTransform() { return m_transform; }

	protected:
		Transform m_transform;
		std::shared_ptr<Model> m_model;

	private:
	};
}