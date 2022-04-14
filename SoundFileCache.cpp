#include "SoundFileCache.h"

SoundFileCache::SoundFileCache() {}

SoundFileCache::~SoundFileCache() {
	std::for_each(_sounds.begin(), _sounds.end(), Deallocator<sf::SoundBuffer*>());
	std::for_each(_music.begin(), _music.end(), Deallocator<sf::Music*>());
}

sf::Sound SoundFileCache::GetSound(std::string soundName) const {
	std::map<std::string, sf::SoundBuffer*>::iterator itr = _sounds.find(soundName);
	if (itr == _sounds.end()) {
		sf::SoundBuffer* soundBuffer = new sf::SoundBuffer();
		if (!soundBuffer->loadFromFile(soundName)) {
			delete soundBuffer;
			throw SoundNotFoundException(soundName + "was not found in call to SoundFileCache::GetSound");
		}

		std::map<std::string, sf::SoundBuffer*>::iterator res =
			_sounds.insert(std::pair<std::string, sf::SoundBuffer*>(soundName, soundBuffer)).first;

		sf::Sound sound;
		sound.setBuffer(*soundBuffer);
		return sound;
	}
	else {
		sf::Sound sound;
		sound.setBuffer(*itr->second);
		return sound;
	}
	throw SoundNotFoundException(soundName + "wasn not found in call to SoundFileCahce::GetSound");
}

sf::Music* SoundFileCache::GetSong(std::string SoundName) const {

}