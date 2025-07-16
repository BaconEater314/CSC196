#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Math/Transform.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Game/Actor.h"

#include <vector>

int main(int argc, char* argv[]) {
    
    //Adding Models
    //bacon::Model model;
    
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
        {-5, -5},
    };

    bacon::Model* model = new bacon::Model{ points, {0,0,1} };

    std::vector <bacon::Actor> actors;
    for (int i = 0; i < 10; i++) {
        bacon::Transform transform{ bacon::vec2{640,512},0,20 };
        bacon::Actor actor{ transform, model };
        actors.push_back(actor);
    }

    // Main loop
    // This is where all the code that runs the code goes.
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

        // all control code after this line
        renderer.Clear();


        // movement and rotation code
        float playerSpeed = 200;

        //if (input.GetKeyDown(SDL_SCANCODE_A)) transform.rotation -= bacon::math::degToRad(90 * time.GetDeltaTime());
        //if (input.GetKeyDown(SDL_SCANCODE_D)) transform.rotation += bacon::math::degToRad(90 * time.GetDeltaTime());
        bacon::vec2 direction{ 0,0 };
        if (input.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1; //playerSpeed * time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1; // playerSpeed* time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1; // playerSpeed* time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; // playerSpeed* time.GetDeltaTime();

        if (direction.LengthSqr() > 0) {
            for (auto actor : actors) {
                direction = direction.Normalized();
                actor.getTransform().position += (direction * playerSpeed) * time.GetDeltaTime();
            }
        }

        //drawing shapes
        //actor.Draw(renderer);
        for (auto actor : actors) {
            actor.Draw(renderer);
        }


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

        // drawing with mouse
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

        //model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10.0f);

        //clears the screen
        if (input.GetKeyDown(SDL_SCANCODE_C) && !input.GetPrevKeyDown(SDL_SCANCODE_C)) {
            points.clear();
        }


        // all control code before this spot
        renderer.Present();
    }
    audio.Kill();
    renderer.Clear();
    
}