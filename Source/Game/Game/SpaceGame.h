#pragma once
#include "GameEngine/Game.h"
#include "GameEngine/Scene.h"

class SpaceGame : bacon::Game {
public:
	SpaceGame() = default;

	bool Initialize() override;
	void Kill() override;
	void Update() override;
	void Draw() override;

private:
};