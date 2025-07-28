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

#include <vector>

using namespace bacon;

bool SpaceGame::Initialize() {
    m_scene = std::make_unique<Scene>();

    std::vector<vec2> points{
        { -2, -1 },
        { -4, -1 },
        { -4, -2 },
        { -2, -2 },
        { -2, 1 },
        { -4, 1 },
        { -4, 2 },
        { -2, 2 },
        { -2, 1 },
        { -1, 1 },
        { 0, 1 },
        { 1, 2 },
        { 3, 2 },
        { 4, 1 },
        { 4, -1 },
        { 3, -2 },
        { 1, -2 },
        { 0, -1 },
        { 0, 1 },
        { 0, -1 },
        { -2, -1 },
    };

    //create player
    std::shared_ptr<Model> model = std::make_shared<Model>(points, vec3{ 1,0,0 });
    
    Transform transform{vec2{bacon::GetEngine().GetRenderer().GetWidth() * 0.5f,GetEngine().GetRenderer().GetHeight() * 0.5f},0,20};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    player->speed = 750.0f;
    player->rotationRate = 180.0f;
    player->damping = 1.5f;
    player->name = "player";

    m_scene->AddActor(std::move(player));

    std::vector<vec2> enemyPoints{
        { 3, 0 },
        { -3, -2 },
        { -1, 0 },
        { -3, 2 },
        { 3, 0 },
    };


    //create enemies
    std::shared_ptr<Model> enemyModel = std::make_shared<Model>(enemyPoints, vec3{ 1,1,0 });
    for (int i = 0; i < 10; i++) {
        Transform transform{vec2{random::GetRandomFloat() * bacon::GetEngine().GetRenderer().GetWidth(), random::GetRandomFloat() * GetEngine().GetRenderer().GetHeight() * 0.5f},0,20};
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
        enemy->damping = 1.5f;
        enemy->speed = 400;// (random::GetRandomFloat() * 500) + 500;
        m_scene->AddActor(std::move(enemy));
    }

    return true;
}

void SpaceGame::Kill(){

}

void SpaceGame::Update(){
    m_scene->Update(GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw(){
    m_scene->Draw(GetEngine().GetRenderer());
}
