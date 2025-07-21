#pragma once
#include "../../Engine/GameEngine/Actor.h"

class Player : public bacon::Actor {
public:
	Player() = default;
	Player(const bacon::Transform& transform, std::shared_ptr<bacon::Model> model) :
		Actor{ transform, model }
	{ }

	void Update(float dt) override;

private:
};