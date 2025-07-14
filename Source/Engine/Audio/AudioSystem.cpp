#include "AudioSystem.h"
#include "../Core/StringHelper.h"

#include <fmod_errors.h>
#include <iostream>

namespace bacon{
	/// <summary>
	/// Checks if an FMOD operation was succeful and logs an error message if it was not
	/// </summary>
	/// <param name="result">The FMOD_RESULT value returned by an FMOD function call.</param>
	/// <returns>True if the FMOD operation was successful (FMOD_OK); otherwise false.</returns>
	bool AudioSystem::checkFMODResult(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << FMOD_ErrorString(result) << std::endl;
			return false;
		}
		return true;
	}

	bool AudioSystem::Initialize() {
		FMOD_RESULT result = FMOD::System_Create(&m_system);
		if (!checkFMODResult(result)) return false;

		void* extradriverdata = nullptr;
		result = m_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		if (!checkFMODResult(result)) return false;

		return true;
	}
	void AudioSystem::Kill() {
		checkFMODResult(m_system->release());
	}

	void AudioSystem::Update() {
		checkFMODResult(m_system->update());
	}

	/// <summary>
	///	Attempts to add a new sound to the audio system from a file associating it with a specified file name
	/// </summary>
	/// <param name="filename"></param>
	/// <param name="name"></param>
	/// <returns></returns>
	bool AudioSystem::addSound(const std::string& filename, const std::string& name){
		//checks to see if the sound already exists in the sound map
		std::string key = (name.empty()) ? filename : name;
		key = toLower(key);
		if (m_sounds.find(key) != m_sounds.end()) {
			std::cerr << "Audio System : name already exists " << key << std::endl;
			return false;
		}

		//create sound from key
		FMOD::Sound* sound = nullptr;
		FMOD_RESULT result = m_system->createSound(filename .c_str(), FMOD_DEFAULT, 0, &sound);
		if (!checkFMODResult(result)) return false;

		//insert sound into map
		m_sounds[key] = sound;

		return true;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool AudioSystem::playSound(const std::string& name){
		std::string key = name;
		key = toLower(key);

		if(m_sounds.find(key) == m_sounds.end()){
			std::cerr << "Audio System : name doesn't exists " << key << std::endl;
			return false;
		}

		FMOD_RESULT result = m_system->playSound(m_sounds[key], 0, false, nullptr);
		if (!checkFMODResult(result)) return false;

		return true;
	}
}