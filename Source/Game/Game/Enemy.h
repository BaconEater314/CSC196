#pragma once
#include "../../Engine/GameEngine/Actor.h"

class Enemy : public bacon::Actor {
public:
	Enemy() = default;
	Enemy(const bacon::Transform& transform, std::shared_ptr<bacon::Model> model) :
		Actor{ transform, model }
	{ }

	void Update(float dt) override;

	float speed = 200;
private:
};