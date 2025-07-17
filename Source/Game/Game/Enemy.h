#pragma once
#include "../../Engine/Game/Actor.h"

class Enemy : public bacon::Actor {
public:
	Enemy() = default;
	Enemy(const bacon::Transform& transform, std::shared_ptr<bacon::Model> model) :
		Actor{ transform, model }
	{ }

	void Update(float dt) override;

private:
};