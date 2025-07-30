#pragma once
#include "GameEngine/Game.h"
#include "GameEngine/Scene.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

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
	void Update(float dt) override;
	void Draw(class bacon::Renderer& renderer) override;

	void OnPlayerDeath();

private:
	GameState m_gameState = GameState::Initialize;
	float m_enemySpawnTimer{ 0 };
	float m_stateTimer { 0 };

	std::shared_ptr<class bacon::Font> m_titleFont;
	std::shared_ptr<class bacon::Font> m_uiFont;

	std::unique_ptr<class bacon::Text> m_titleText;
	std::unique_ptr<class bacon::Text> m_scoreText;
	std::unique_ptr<class bacon::Text> m_livesText;
};