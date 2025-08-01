#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>

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
        float SetColor(float r, float g, float b, float a = 1.0f);

        void DrawLine(float x1, float y1, float x2, float y2);
        void DrawPoint(float x, float y);

        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

    private:
        friend class Text; 
        SDL_Window* m_window{ nullptr };
        SDL_Renderer* m_renderer{ nullptr };

        int m_width{ 0 };
        int m_height{ 0 };
    };
}