#include <Core/Random.h>
#include <Math/Vecttor2.h>
#include <iostream>
#include <Renderer/Renderer.h>

int main(int argc, char* argv[]) {
    bacon::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Bacon Engine", 1280, 1024);

    SDL_Event e;
    bool quit = false;

    vec2(30, 40);

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
    }

    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.Clear();

    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.DrawLine(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024, bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
    
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.DrawPoint(v.x, v.y);
    renderer.DrawPoint(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);

    renderer.Present();
}