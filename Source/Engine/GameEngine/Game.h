#pragma once

#include <memory>

namespace bacon {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;
		virtual void Kill() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	public:
		std::unique_ptr<class Scene> m_scene;
	};
}