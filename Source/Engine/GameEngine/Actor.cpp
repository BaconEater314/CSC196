#include "Actor.h"
#include "../Renderer/Model.h"

namespace bacon{
	void Actor::Update(float dt) {
		if (!alive) return;

		if (lifespan != 0) {
			lifespan -= dt;
			alive != lifespan <= 0;
		}

		transform.position += velocity * dt;
		velocity = velocity * (1.0f / (1.0f + damping * dt));
	}

	void Actor::Draw(Renderer& renderer) {
		if (!alive) return;

		m_model->Draw(renderer, transform);
	}

	float Actor::GetRadius() {
		return(m_model) ? m_model->GetRadius() * transform.scale * 0.9f : 0;
	}
}