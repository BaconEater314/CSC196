#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"

#include <vector>
#include <iostream>
#include <fmod.hpp>

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
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);



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

    FMOD::Sound* sound = nullptr;
    
    std::vector<FMOD::Sound*> sounds;
    audio->createSound("drums/bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("drums/snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("drums/clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("drums/cowbell.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("pipe.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("fart.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("yippee.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    // Main loop
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) {
            audio->playSound(sounds[0], 0, false, nullptr);
            std::cout << "Q pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) {
            audio->playSound(sounds[1], 0, false, nullptr);
            std::cout << "W pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) {
            audio->playSound(sounds[2], 0, false, nullptr);
            std::cout << "E pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R)) {
            audio->playSound(sounds[3], 0, false, nullptr);
            std::cout << "R pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_P) && !input.GetPrevKeyDown(SDL_SCANCODE_P)) {
            audio->playSound(sounds[4], 0, false, nullptr);
            std::cout << "P pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_F) && !input.GetPrevKeyDown(SDL_SCANCODE_F)) {
            audio->playSound(sounds[5], 0, false, nullptr);
            std::cout << "F pressed\n";
        }
        else if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y)) {
            audio->playSound(sounds[6], 0, false, nullptr);
            std::cout << "Y pressed\n";
        }

        
        
        audio->update();
        input.Update();
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        if (input.GetMouseButtonDown((uint8_t)bacon::InputSystem::MouseButton::Left)) {
            std::cout << "Mouse pressed\n";
        }
        
        bacon::vec2 mouse = input.GetMoustPosition();
        //std::cout << mouse.x << " " << mouse.y << std::endl;

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