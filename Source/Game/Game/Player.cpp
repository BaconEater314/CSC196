#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"

using namespace bacon;

void Player::Update(float dt){

    float rotate = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 1;

    transform.rotation += (rotate * rotationRate) * dt;
    
    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    vec2 direction{ 1,0 };
    vec2 force = direction.Rotate(math::degToRad(transform.rotation)) * thrust * speed;
    velocity += force * dt;

    transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
    transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());

    Actor::Update(dt);
}
