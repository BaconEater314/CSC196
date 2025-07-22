#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "GameEngine/Scene.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Engine.h"
#include "Player.h"

#include <vector>

using namespace bacon;

bool SpaceGame::Initialize() {
    std::unique_ptr<Scene> m_scene = std::make_unique<bacon::Scene>();

    
    /*Color Vector(R, G, B) {
        { 1.0, 0.0, 0.0 },
    }*/

    std::vector<vec2> points{
        { -1, -2 },
        { 1, -2 },
        { 1, -4 },
        { 3, 0 },
        { 3, 2 },
        { 1, 3 },
        { -1, 3 },
        { -3, 2 },
        { -3, 0 },
        { -1, -4 },
        { -1, -2 },
    };

    std::shared_ptr<Model> model = std::make_shared<Model>(points, vec3{ 0,0,1 });

    
    Transform transform{vec2{bacon::GetEngine().GetRenderer().GetWidth() * 0.5f,GetEngine().GetRenderer().GetHeight() * 0.5f},0,20};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    m_scene->AddActor(std::move(player));

}

void SpaceGame::Kill(){

}

void SpaceGame::Update(){

}

void SpaceGame::Draw(){
}
