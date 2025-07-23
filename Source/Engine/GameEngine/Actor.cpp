#include "Actor.h"
#include "../Renderer/Model.h"

namespace bacon{
	void Actor::Update(float dt) {
		transform.position += velocity * dt;
		velocity = velocity * (1.0f / (1.0f + damping * dt));
	}

	void Actor::Draw(Renderer& renderer) {
		m_model->Draw(renderer, transform);
	}
}