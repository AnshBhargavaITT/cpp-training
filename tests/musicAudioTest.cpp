#include <gtest/gtest.h>
#include "song.h"
#include "mockMusicPlayer.h"
using ::testing::Return ;
using ::testing::_;

class GivenAudioPlayer : public ::testing::Test
{
public:
    MockMusicPlayer mockPlayer;

    void SetUp() override
    {
        mockPlayer.createPlaylist("Workout");
        mockPlayer.addSongToPlaylist("Workout", Song("Jump", "03:20", "songs/jump.ogg"));
        mockPlayer.addSongToPlaylist("Workout", Song("Run", "04:10", "songs/run.ogg"));
        mockPlayer.selectActivePlaylist("Workout");
    }
};

TEST_F(GivenAudioPlayer, WhenPlayCurrentSong_OpenAudioFileAndPlayAudio)
{
    EXPECT_CALL(mockPlayer, openAudioFile("songs/jump.ogg")).Times(1).WillOnce(Return(true));

    EXPECT_CALL(mockPlayer, playAudio()).Times(1);

    EXPECT_TRUE(mockPlayer.playCurrentSong());
}

TEST_F(GivenAudioPlayer, WhenPauseCurrentSong_PauseAudio)
{
    EXPECT_CALL(mockPlayer, openAudioFile(_)).WillOnce(Return(true));

    EXPECT_CALL(mockPlayer, playAudio()).Times(1);

    EXPECT_CALL(mockPlayer, pauseAudio()).Times(1);

    EXPECT_TRUE(mockPlayer.playCurrentSong());

    EXPECT_TRUE(mockPlayer.pauseCurrentSong());
}
