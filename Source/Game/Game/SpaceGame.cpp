#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "GameEngine/Scene.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "GameEngine/Game.h"
#include "Input/InputSystem.h"
#include "GameData.h"
#include "Core/Time.h"
#include "GameEngine/Actor.h"

#include <vector>

using namespace bacon;

bool SpaceGame::Initialize() {
    m_scene = std::make_unique<Scene>(this);

    m_titleFont = std::make_shared<Font>();
    m_titleFont->Load("Surprise Valentine.ttf",128);

    m_uiFont = std::make_shared<Font>();
    m_uiFont->Load("Surprise Valentine.ttf", 48);

    m_titleText = std::make_unique<Text>(m_titleFont);
    m_scoreText = std::make_unique<Text>(m_uiFont);
    m_livesText = std::make_unique<Text>(m_uiFont);

    return true;
}

void SpaceGame::Kill(){

}

void SpaceGame::Update(){
    switch (m_gameState){
    case SpaceGame::GameState::Initialize:
        m_gameState = GameState::StartGame;
        break;
    case SpaceGame::GameState::Title:
        if (GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
            m_gameState = GameState::StartGame;
        }
        break;
    case SpaceGame::GameState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_gameState = GameState::StartRound;
        break;
    case SpaceGame::GameState::StartRound:
        //create player
        std::shared_ptr<Model> model = std::make_shared<Model>(GameData::shipPoints, vec3{ 1,0,0 });
        Transform transform{ vec2{bacon::GetEngine().GetRenderer().GetWidth() * 0.5f,GetEngine().GetRenderer().GetHeight() * 0.5f},0,20 };
        auto player = std::make_unique<Player>(transform, model);
        player->speed = 750.0f;
        player->rotationRate = 180.0f;
        player->damping = 1.5f;
        player->name = "player";
        player->tag = "player";

        m_scene->AddActor(std::move(player));
        m_gameState = GameState::Game;
        break;

    case SpaceGame::GameState::Game:
        m_enemySpawnTimer -= dt;
        if (m_enemySpawnTimer <= 0) {
            m_enemySpawnTimer = 4;

            //create enemies
            std::shared_ptr<Model> enemyModel = std::make_shared<Model>(GameData::enemyPoints, vec3{ 1,1,0 });
            Transform transform{ vec2{random::GetRandomFloat() * bacon::GetEngine().GetRenderer().GetWidth(), random::GetRandomFloat() * GetEngine().GetRenderer().GetHeight() * 0.5f},0,20 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->damping = 1.5f;
            enemy->speed = (random::GetRandomFloat() * 500) + 500;
            enemy->tag = "enemy";
            m_scene->AddActor(std::move(enemy));
        }
        break;
    case SpaceGame::GameState::PlayerDead:
        break;
    case SpaceGame::GameState::GameOver:
        break;
    default:
        break;
    }

    m_scene->Update(GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw(){
    m_scene->Draw(GetEngine().GetRenderer());
}
