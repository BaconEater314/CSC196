#include "Enemy.h"
#include "Engine.h"
#include "Renderer/Renderer.h"
#include "GameEngine/Scene.h"
#include "GameEngine/Game.h"
#include "GameRocket.h"
#include "GameData.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"

using namespace bacon;

void Enemy::Update(float dt){

    Actor* player = scene->GetActorByName("player");
    if (player) {
        vec2 direction{ 0,0 };
        direction = player->transform.position - transform.position;
        direction = direction.Normalized();
        transform.rotation = math::radToDeg(direction.Angle());
    }


    vec2 force = vec2{1,0}.Rotate(math::degToRad(transform.rotation)) * speed;
    velocity += force * dt;

    transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
    transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());

    fireTimer -= dt;
    if (fireTimer <= 0) {
        fireTimer = fireRate;

        std::shared_ptr<Model> model = std::make_shared<Model>(GameData::rocketPoints, vec3{ 1,1,1 });
        Transform transform{ this->transform.position, this->transform.rotation, 2.0f };
        auto rocket = std::make_unique<Rocket>(transform, model);
        rocket->speed = 1500.0f;
        rocket->lifespan = 1.5f;
        rocket->name = "rocket";
        rocket->tag = "enemy";

        scene->AddActor(std::move(rocket));
    }



    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other) {
    if (other->tag != tag) {
        alive = false;
        scene->GetGame()->AddPoints(100);
    }
}
