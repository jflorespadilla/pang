#pragma once
#include "IAudioProvider.h"
#include <SFML/Audio.hpp>
#include "SoundFileCache.h"

class SFMLSoundProvider :
    public IAudioProvider
{
public:
    SFMLSoundProvider();
    //~SFMLSoundProvider();

    void PlaySound(std::string filename);
    void PlaySong(std::string filename, bool looping = false);
    void StopAllSounds();

    bool IsSoundPlaying();
    bool IsSongPlaying();

private:
    static const int MAX_SOUND_CHANNELS = 5;

    SoundFileCache _soundFileCache;
    sf::Sound _currentSounds[MAX_SOUND_CHANNELS];
    std::string _currentSongName;
};

