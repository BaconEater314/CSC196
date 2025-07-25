#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "../Core/StringHelper.h"

namespace bacon {
	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			actor->Update(dt);
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor :  m_actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor){
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}
	Actor* Scene::GetActorByName(const std::string& name){
		for (auto& actor : m_actors) {
			if (actor->name == name) {
				return actor.get();
			}
		}
		return nullptr;
	}
}