#include <gtest/gtest.h>
#include "song.h"

class GivenSong : public ::testing::Test
{
public:
    Song song{"Jump", "03:20", "songs/jump.ogg"};
};

TEST_F(GivenSong, WhenGetTitle_ThenReturnTitle)
{
    EXPECT_EQ(song.getTitle(), "Jump");
}

TEST_F(GivenSong, WhenGetDuration_ThenReturnDuration)
{
    EXPECT_EQ(song.getDuration(), "03:20");
}

TEST_F(GivenSong, WhenGetFilePath_ThenReturnFilePath)
{
    EXPECT_EQ(song.getFilePath(), "songs/jump.ogg");
}

TEST_F(GivenSong, WhenSetDuration_ThenUpdateDuration)
{
    song.setDuration("04:10");
    EXPECT_EQ(song.getDuration(), "04:10");
}

TEST_F(GivenSong, WhenSongsHaveSameAttributes_ThenOperatorEqualsReturnsTrue)
{
    Song otherSong("Jump", "03:20", "songs/jump.ogg");
    EXPECT_TRUE(song == otherSong);
}

TEST_F(GivenSong, WhenSongsDiffer_ThenOperatorEqualsReturnsFalse)
{
    Song otherSong("Run", "03:20", "songs/jump.ogg");
    EXPECT_FALSE(song == otherSong);
}
