#pragma once
#include "GameEngine/Game.h"
#include "GameEngine/Scene.h"

class SpaceGame : bacon::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver,
	};

public:
	SpaceGame() = default;

	bool Initialize() override;
	void Kill() override;
	void Update() override;
	void Draw() override;

private:
	GameState m_gameState = GameState::Initialize;
	float m_enemySpawnTimer{ 0 };
};