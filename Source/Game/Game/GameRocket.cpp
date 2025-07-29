#include "GameRocket.h"
#include "Engine.h"
#include "GameEngine/Scene.h"
#include "Renderer/Renderer.h"
#include "Player.h"

using namespace bacon;

void Rocket::Update(float dt) {
    vec2 force = vec2{ 1,0 }.Rotate(math::degToRad(transform.rotation)) * speed;
    velocity = force;

    transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
    transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());

    Actor::Update(dt);
}

void Rocket::OnCollision(Actor* other){
    if (other->tag != tag) {
        alive = false;
    }
}
