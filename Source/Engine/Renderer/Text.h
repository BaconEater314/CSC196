#pragma once
#include "Renderer.h"
#include "../Math/Vector3.h"
#include "Font.h"

struct SDL_Texture;

namespace bacon {
	class Text {
	public:
		Text() = default;
		Text(Font* font) : m_font{ font } {}
		~Text();

		bool Create(Renderer& renderer, const std::string& text, const vec3& color);
		void Draw(Renderer& renderer, float x, float y);

	private:
		Font* m_font;
		SDL_Texture* m_texture;
	};
}