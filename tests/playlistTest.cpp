#include <gtest/gtest.h>
#include "playlist.h"

class GivenPlaylist : public ::testing::Test
{
public:
    Playlist playlist;

    void SetUp() override
    {
        playlist.setName("Workout");
        playlist.addSong(Song("Jump", "03:20", "songs/jump.ogg"));
        playlist.addSong(Song("Run", "04:10", "songs/run.ogg"));
    }
};

TEST_F(GivenPlaylist, WhenAddNewSong_ThenSongIsAdded)
{
    EXPECT_TRUE(playlist.addSong(Song("Calm", "03:00", "relax.ogg")));

    EXPECT_EQ(playlist.getSongs().size(), 3);
}

TEST_F(GivenPlaylist, WhenAddDuplicateSong_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.addSong(Song("Jump", "03:20", "songs/jump.ogg")));
}

TEST_F(GivenPlaylist, WhenRemoveExistingSong_ThenSongIsRemoved)
{
    EXPECT_TRUE(playlist.removeSong("Jump"));

    EXPECT_EQ(playlist.getSongs().size(), 1);
}

TEST_F(GivenPlaylist, WhenRemoveNonExistingSong_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.removeSong("Jogging"));
}

TEST_F(GivenPlaylist, WhenMoveFirstSongUp_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.moveSongUp("Jump"));
}

TEST_F(GivenPlaylist, WhenMoveSecondSongUp_ThenSwapsWithFirst)
{
    EXPECT_TRUE(playlist.moveSongUp("Run"));

    EXPECT_EQ(playlist.getSongs()[0].getTitle(), "Run");
}

TEST_F(GivenPlaylist, WhenMoveLastSongDown_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.moveSongDown("Run"));
}

TEST_F(GivenPlaylist, WhenMoveFirstSongDown_ThenSwapsWithSecond)
{
    EXPECT_TRUE(playlist.moveSongDown("Jump"));

    EXPECT_EQ(playlist.getSongs()[1].getTitle(), "Jump");
}

TEST_F(GivenPlaylist, WhenSetValidSongIndex_ThenIteratorIsSet)
{
    EXPECT_TRUE(playlist.setCurrentSongIndex(1));

    EXPECT_EQ(playlist.getCurrentSong()->getTitle(), "Run");
}

TEST_F(GivenPlaylist, WhenSetInvalidSongIndex_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.setCurrentSongIndex(5));
}

TEST_F(GivenPlaylist, WhenResetToFirstSong_ThenIteratorPointsToFirst)
{
    playlist.resetToFirstSong();

    EXPECT_EQ(playlist.getCurrentSong()->getTitle(), "Jump");
}

TEST_F(GivenPlaylist, WhenSkipToNextSong_ThenIteratorMovesForward)
{
    playlist.resetToFirstSong();

    EXPECT_TRUE(playlist.skipToNextSong());

    EXPECT_EQ(playlist.getCurrentSong()->getTitle(), "Run");
}

TEST_F(GivenPlaylist, WhenSkipToPreviousSong_ThenIteratorMovesBack)
{
    playlist.setCurrentSongIndex(1);

    EXPECT_TRUE(playlist.skipToPreviousSong());

    EXPECT_EQ(playlist.getCurrentSong()->getTitle(), "Jump");
}

TEST_F(GivenPlaylist, WhenCheckIsEmptyOnNonEmptyPlaylist_ThenReturnFalse)
{
    EXPECT_FALSE(playlist.isEmpty());
}

TEST_F(GivenPlaylist, WhenGetName_ThenReturnName)
{
    EXPECT_EQ(playlist.getName(), "Workout");
}
