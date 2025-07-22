#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"

using namespace bacon;

void Player::Update(float dt){

    float speed = 200;
    float rotationRate = 180;

    float rotate = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 1;

    m_transform.rotation += (rotate * rotationRate) * dt;
    
    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    vec2 direction{ 1,0 };
    vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
    velocity += force * dt;

    Actor::Update(dt);
}
