#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Math/Transform.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "GameEngine/Scene.h"
#include "GameEngine/Actor.h"
#include "Engine.h"
#include "Game/SpaceGame.h"

#include "Game/Player.h"

#include <vector>
#include <memory>

using namespace bacon;

int main(int argc, char* argv[]) {
    
    //initialize Engine
    GetEngine().Initialize();

    //initialize scene
    //bacon::Scene scene;

    //initialize game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();

    SDL_Event e;
    bool quit = false;

    //create stars
    std::vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{random::getRandomFloat() * 1280 ,random::getRandomFloat() * 1024 });
    }

    vec2(30, 40);

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    // sound work
    GetEngine().GetAudio().addSound("drums/bass.wav", "bass");
    GetEngine().GetAudio().addSound("drums/snare.wav", "snare");
    GetEngine().GetAudio().addSound("drums/clap.wav", "clap");
    GetEngine().GetAudio().addSound("drums/cowbell.wav", "cowbell");
    GetEngine().GetAudio().addSound("pipe.wav", "pipe");
    GetEngine().GetAudio().addSound("fart.wav", "fart");
    GetEngine().GetAudio().addSound("yippee.wav", "yippee");
    

    // Main loop
    // This is where all the code that runs the code goes.
    /*while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            
        }

        GetEngine().Update();
        //scene.Update(GetEngine().GetTime().GetTime());

        vec3 color{ 0,0,0 };
        GetEngine().GetRenderer().SetColor((float)color.r, color.g, color.b);

        // all control code after this line
        GetEngine().GetRenderer().Clear();

        // movement and rotation code
        float playerSpeed = 200;

        vec2 direction{ 0,0 };
        

        //drawing shapes
        //actor.Draw(renderer);
        for (auto& actor : actors) {
            actor->Draw(GetEngine().GetRenderer());
        }


        //quits the program when pressing escape.
        if (GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //soundboard
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_Q) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_Q)) {
            GetEngine().GetAudio().playSound("bass");
        }
        //if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_W)) { GetEngine().GetAudio().playSound("snare"); }
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_E) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_E)) { GetEngine().GetAudio().playSound("clap"); }
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_R) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_R)) { GetEngine().GetAudio().playSound("cowbell"); }
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_P) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_P)) { GetEngine().GetAudio().playSound("pipe"); }
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_F) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_F)) { GetEngine().GetAudio().playSound("fart"); }
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_Y) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_Y)) { GetEngine().GetAudio().playSound("yippee"); }

        // drawing with mouse
        if (GetEngine().GetInput().GetMouseButtonDown((uint8_t)InputSystem::MouseButton::Left)) {
            vec2 position = GetEngine().GetInput().GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
            GetEngine().GetRenderer().DrawPoint(GetEngine().GetInput().GetMousePosition().x, GetEngine().GetInput().GetMousePosition().y);
        }
        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
            GetEngine().GetRenderer().SetColor((uint8_t)random::getRandom(256), random::getRandom(256), random::getRandom(256));
            GetEngine().GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        //model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10.0f);

        //clears the screen
        if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_C) && !GetEngine().GetInput().GetPrevKeyDown(SDL_SCANCODE_C)) {
            points.clear();
        }


        // all control code before this spot
        GetEngine().GetRenderer().Present();
    }*/

    GetEngine().GetRenderer().Clear();
    
    GetEngine().Kill();

    return 0;
}