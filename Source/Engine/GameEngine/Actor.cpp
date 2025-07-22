#include "Actor.h"
#include "../Renderer/Model.h"

void bacon::Actor::Update(float dt) {
	m_transform.position += velocity * dt;
}

void bacon::Actor::Draw(Renderer& renderer) {
	m_model->Draw(renderer, m_transform);
}