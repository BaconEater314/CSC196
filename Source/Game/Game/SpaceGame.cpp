#include "SpaceGame.h"
#include "../../Engine/Math/Vector2.h"
#include "../../Engine/Renderer/Model.h"
#include "../../Engine/GameEngine/Scene.h"
#include "../../Engine/Core/Random.h"

#include <vector>

bool SpaceGame::Initialize() {
	//m_scene = std::make_unique<bacon::Scene>();

    std::vector<vec2> points{
        {-5, -5},
        {5, -5},
        {5, 5},
        {-5, 5},
        {-5, -5},
    };

    std::shared_ptr<Model> model = std::make_shared<Model>(points, vec3{ 0,0,1 });

    std::vector<std::unique_ptr<Actor>> actors;
    for (int i = 0; i < 10; i++) {
        Transform transform{ vec2{640,512},0,20 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        actors.push_back(std::move(player));
    }
}

void SpaceGame::Kill(){

}

void SpaceGame::Update(){

}

void SpaceGame::Draw(){
}
