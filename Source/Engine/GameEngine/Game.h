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

		void AddPoints(int points) { m_score += points; }
		int GetPoints() const { return m_score; }

		void SetLive(int lives) { m_lives = lives; }
		int GetLive() const { return m_lives; }

	protected:
		int m_score;
		int m_lives;

	public:
		std::unique_ptr<class Scene> m_scene;
	};
}