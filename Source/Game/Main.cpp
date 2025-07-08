#include <Core/Random.h>
#include <Math/Vector2.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <Core/Time.h>

int main(int argc, char* argv[]) {
    bacon::Time time;
    
    bacon::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Bacon Engine", 1280, 1024);

    SDL_Event e;
    bool quit = false;

    //create stars
    std::vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{ bacon::random::getRandomFloat() * 1280 ,bacon::random::getRandomFloat() * 1024 });
    }

    vec2(30, 40);

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
    }

    
    renderer.SetColor(0, 0, 0);
    renderer.Clear();
    
    vec2 speed{ 120.0f,0 };
    for (vec2 star : stars) {
        star += speed * time.GetDeltaTime();
        if (star[0] > 1280) star.x = 0;
        if (star[0] < 0) star.x = 1280;
        renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
        renderer.DrawPoint(star.x, star.y);
    }

    /*
    
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.Clear();
   
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.DrawLine(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024, bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
    
    renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
    renderer.DrawPoint(v.x, v.y);
    renderer.DrawPoint(bacon::random::getRandomFloat() * 1280, bacon::random::getRandomFloat() * 1024);
    */
    renderer.Present();
}