#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"

#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    bacon::Time time;
    
    bacon::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Bacon Engine", 1280, 1024);

    bacon::InputSystem input;
    input.Initialize();

    SDL_Event e;
    bool quit = false;

    //create stars
    std::vector<bacon::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(bacon::vec2{ bacon::random::getRandomFloat() * 1280 ,bacon::random::getRandomFloat() * 1024 });
    }

    bacon::vec2(30, 40);

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    // Main loop
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        input.Update();
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        if (input.GetMouseButtonDown(0)) {
            std::cout << "Mouse pressed\n";
        }
        
        bacon::vec2 mouse = input.GetMoustPosition();
        std::cout << mouse.x << " " << mouse.y << std::endl;

        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        bacon::vec2 speed{ 120.0f,0 };
        for (bacon::vec2& star : stars) {
            star += speed * time.GetDeltaTime();
            if (star[0] > 1280) star.x = 0;
            if (star[0] < 0) star.x = 1280;
            renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
            renderer.DrawPoint(star.x, star.y);
        }
        for (int i = 0; i < 10; i++) {
        //renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
        //renderer.DrawLine(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024, bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
        }
        renderer.Present();
    }

    
    
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.Clear();
   
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.DrawLine(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024, bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
    
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    //renderer.DrawPoint(v.x, v.y);
    renderer.DrawPoint(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
    
}