#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

namespace bacon {

	Engine& GetEngine(){
		static Engine engine;
		return engine;
	}

	bool Engine::Initialize() {

		m_renderer = std::make_unique<bacon::Renderer>();
		m_renderer->Initialize();
		m_renderer->CreateWindow("Bacon Engine", 1280, 1024);

		//Initialize Input System
		m_input = std::make_unique<bacon::InputSystem>();
		m_input->Initialize();

		// create audio system
		m_audio = std::make_unique<bacon::AudioSystem>();
		m_audio->Initialize();

		return true;
	}

	void Engine::Kill() {
		m_audio->Kill();
		m_input->Kill();
		m_renderer->Kill();
	}

	void Engine::Update() {
		m_time.Tick();
		m_input->Update();
		m_audio->Update();
	}

	void Engine::Draw(){

	}
}