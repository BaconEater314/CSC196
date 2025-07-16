#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"

#include <vector>

int main(int argc, char* argv[]) {
    
    //Adding Models
    bacon::Model model;
    
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
    std::vector<bacon::vec2> points {
        {-5, - 5},
        {5, -5},
        {5, 5},
        {-5, 5},
        {-5, -5}
    };

    // Main loop
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            
        }

        bacon::vec3 color{ 0,0,0 };
        renderer.SetColor((float)color.r, color.g, color.b);

        audio.Update();
        input.Update();

        // first line
        renderer.Clear();

        //quits the program when pressing escape.
        if (input.GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //soundboard
        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) {
            audio.playSound("bass");
        }
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) { audio.playSound("snare"); }
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) { audio.playSound("clap"); }
        if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R)) { audio.playSound("cowbell"); }
        if (input.GetKeyDown(SDL_SCANCODE_P) && !input.GetPrevKeyDown(SDL_SCANCODE_P)) { audio.playSound("pipe"); }
        if (input.GetKeyDown(SDL_SCANCODE_F) && !input.GetPrevKeyDown(SDL_SCANCODE_F)) { audio.playSound("fart"); }
        if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y)) { audio.playSound("yippee"); }

        // drawing
        if (input.GetMouseButtonDown((uint8_t)bacon::InputSystem::MouseButton::Left)) {
            bacon::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
            renderer.DrawPoint(input.GetMousePosition().x, input.GetMousePosition().y);
        }
        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
             renderer.SetColor((uint8_t)bacon::random::getRandom(256), bacon::random::getRandom(256), bacon::random::getRandom(256));
             renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10.0f);

        //clears the screen
        if (input.GetKeyDown(SDL_SCANCODE_C) && !input.GetPrevKeyDown(SDL_SCANCODE_C)) {
            points.clear();
        }


        //final line
        renderer.Present();
    }
    audio.Kill();
    renderer.Clear();

}