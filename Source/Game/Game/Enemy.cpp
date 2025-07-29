#include "Enemy.h"
#include "Engine.h"
#include "Renderer/Renderer.h"
#include "GameEngine/Scene.h"
#include "GameEngine/Game.h"

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

    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other) {
    if (other->tag != tag) {
        alive = false;
        scene->GetGame()->AddPoints(100);
    }
}
