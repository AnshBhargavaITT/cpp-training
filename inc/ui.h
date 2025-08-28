#ifndef UI_H
#define UI_H

#include "musicPlayer.h"

enum Command
{
    CREATE_PLAYLIST = 1,
    ADD_SONG,
    SELECT_PLAYLIST,
    PLAY_SONG,
    PAUSE,
    NEXT,
    PREV,
    MOVE_UP,
    MOVE_DOWN,
    SHOW_PLAYLIST,
    RENAME_PLAYLIST,
    DELETE_PLAYLIST,
    DELETE_SONG,
    QUIT
};

void showCurrentPlaylist(const MusicPlayer &player);

std::string choosePlaylist(const MusicPlayer &player, const std::string &prompt);

bool createPlaylist(MusicPlayer &player);

bool addSongToPlaylist(MusicPlayer &player);

void playFirstSongInPlaylist(MusicPlayer &player, const Playlist *playlist);

void selectPlaylist(MusicPlayer &player);

bool moveSongUp(MusicPlayer &player);

bool moveSongDown(MusicPlayer &player);

void selectAndPlaySong(MusicPlayer &player);

int displayMenuAndGetCommand(const MusicPlayer &player);

void quit(MusicPlayer &player, bool &running, bool hasChanges);

bool deletePlaylist(MusicPlayer &player);

bool renamePlaylist(MusicPlayer &player);

bool deleteSongFromPlaylist(MusicPlayer &player);

#endif