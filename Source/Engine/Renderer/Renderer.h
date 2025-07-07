#pragma once
#include <SDL3/SDL.h>
#include <iostream>

namespace bacon {
    class Renderer {
    public:
        Renderer() = default;

        bool Initialize();
        void Kill();
        bool CreateWindow(const std::string& name, int width, int height);

        void Clear();
        void Present();

        void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
        void DrawLine(float x1, float y1, float x2, float y2);
        void DrawPoint(float x, float y);

    private:
        SDL_Window* m_window{ nullptr };
        SDL_Renderer* m_renderer{ nullptr };
    };

    int main(int argc, char* argv[]) {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
        if (window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
        if (renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

        SDL_Event e;
        bool quit = false;

        // Define a rectangle
        SDL_FRect greenSquare{ 270, 190, 200, 200 };

        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
            SDL_RenderClear(renderer); // Clear the renderer

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
            SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

            SDL_RenderPresent(renderer); // Render the screen
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }
}