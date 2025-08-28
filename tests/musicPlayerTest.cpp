#include <gtest/gtest.h>
#include "musicPlayer.h"
#include "song.h"

class GivenMusicPlayer : public ::testing::Test
{
public:
    MusicPlayer player;

    void SetUp() override
    {
        player.createPlaylist("Workout");
        player.addSongToPlaylist("Workout", Song("Jump", "03:20", "songs/jump.ogg"));
        player.addSongToPlaylist("Workout", Song("Run", "04:10", "songs/run.ogg"));
        player.selectActivePlaylist("Workout");
    }
};

TEST_F(GivenMusicPlayer, WhenCreateDuplicatePlaylist_ThenReturnFalse)
{
    EXPECT_FALSE(player.createPlaylist("Workout"));
}

TEST_F(GivenMusicPlayer, WhenAddSongToNonExistingPlaylist_ThenReturnFalse)
{
    EXPECT_FALSE(player.addSongToPlaylist("Relax", Song("Calm", "03:00", "relax.ogg")));
}

TEST_F(GivenMusicPlayer, WhenSelectExistingPlaylist_ThenReturnTrue)
{
    EXPECT_TRUE(player.selectActivePlaylist("Workout"));
}

TEST_F(GivenMusicPlayer, WhenSelectNonExistingPlaylist_ThenReturnFalse)
{
    EXPECT_FALSE(player.selectActivePlaylist("Bollywood"));
}

TEST_F(GivenMusicPlayer, WhenMoveSongUp_ThenOrderChanges)
{
    EXPECT_TRUE(player.moveSongUpInPlaylist("Workout", "Run"));
}

TEST_F(GivenMusicPlayer, WhenMoveSongDown_ThenOrderChanges)
{
    EXPECT_TRUE(player.moveSongDownInPlaylist("Workout", "Jump"));
}

TEST_F(GivenMusicPlayer, WhenRemoveSong_ThenSongRemoved)
{
    EXPECT_TRUE(player.removeSongFromPlaylist("Workout", "Jump"));
}

TEST_F(GivenMusicPlayer, WhenRemoveNonExistentSong_ThenReturnFalse)
{
    EXPECT_FALSE(player.removeSongFromPlaylist("Workout", "Jogging"));
}

TEST_F(GivenMusicPlayer, WhenDeletePlaylist_ThenPlaylistRemoved)
{
    EXPECT_TRUE(player.deletePlaylist("Workout"));
}

TEST_F(GivenMusicPlayer, WhenRenamePlaylist_ThenPlaylistNameIsRenamed)
{
    EXPECT_TRUE(player.renamePlaylist("Workout", "MorningRoutine"));

    EXPECT_FALSE(player.selectActivePlaylist("Workout"));

    EXPECT_TRUE(player.selectActivePlaylist("MorningRoutine"));
}

TEST_F(GivenMusicPlayer, WhenSaveToFileAndLoad_ThenStatePersists)
{
    player.saveToFile("playlist.txt");

    EXPECT_TRUE(player.loadFromFile("playlist.txt"));

    EXPECT_TRUE(player.selectActivePlaylist("Workout"));
}
