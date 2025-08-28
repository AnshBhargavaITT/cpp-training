#ifndef MOCK_MUSIC_PLAYER_H
#define MOCK_MUSIC_PLAYER_H

#include <gmock/gmock.h>
#include "musicPlayer.h"

class MockMusicPlayer : public MusicPlayer
{
public:
    MockMusicPlayer() = default;

    ~MockMusicPlayer() = default;

    MOCK_METHOD(bool, openAudioFile, (const std::string &filepath), (override));

    MOCK_METHOD(void, playAudio, (), (override));

    MOCK_METHOD(void, pauseAudio, (), (override));

    MOCK_METHOD(void, stopAudio, (), (override));

    MOCK_METHOD(sf::Music::Status, getAudioStatus, (), (const, override));
};

#endif
