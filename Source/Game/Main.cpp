#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include <vector>

int main(int argc, char* argv[]) {
    //Making Time
    bacon::Time time;

    //Initialize Renderer
    bacon::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Bacon Engine", 1280, 1024);

    //Initialize Input Ssytem
    bacon::InputSystem input;
    input.Initialize();

    // create audio system
    bacon::AudioSystem audio;
    audio.Initialize();


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

    // sound work
    audio.addSound("drums/bass.wav", "bass");
    audio.addSound("drums/snare.wav", "snare");
    audio.addSound("drums/clap.wav", "clap");
    audio.addSound("drums/cowbell.wav", "cowbell");
    audio.addSound("pipe.wav", "pipe");
    audio.addSound("fart.wav", "fart");
    audio.addSound("yippee.wav", "yippee");

    // drawing work
    std::vector<bacon::vec2> points;

    // Main loop
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //soundboard
        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) {
            audio.playSound("bass");
            std::cout << "Bass played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) {
            audio.playSound("snare");
            std::cout << "Snare played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) {
            audio.playSound("clap");
            std::cout << "Clap played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R)) {
            audio.playSound("cowbell");
            std::cout << "Cowbell played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_P) && !input.GetPrevKeyDown(SDL_SCANCODE_P)) {
            audio.playSound("pipe");
            std::cout << "metal pipe played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_F) && !input.GetPrevKeyDown(SDL_SCANCODE_F)) {
            audio.playSound("fart");
            std::cout << "reverb fart played\n";
        }
        if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y)) {
            audio.playSound("yippee");
            std::cout << "yippee played\n";
        }

        // drawing
        if (input.GetMouseButtonDown((uint8_t)bacon::InputSystem::MouseButton::Left)) {
            bacon::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
            renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
            renderer.DrawPoint(input.GetMousePosition().x, input.GetMousePosition().y);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        if (input.GetKeyDown(SDL_SCANCODE_C) && !input.GetPrevKeyDown(SDL_SCANCODE_C)) {
            points.clear();
        }

        audio.Update();
        input.Update();

        renderer.SetColor(0, 0, 0);
        renderer.Clear();
        renderer.Present();
    }
    audio.Kill();
    renderer.Clear();

}