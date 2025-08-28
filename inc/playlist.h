#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include <vector>
#include <string>

class Playlist
{
    std::string playlistName;
    std::vector<Song> songs;
    std::vector<Song>::iterator songIterator;

public:
    Playlist();

    Playlist(const std::string &name);

    bool addSong(const Song &song);

    bool removeSong(const std::string &title);

    bool moveSongUp(const std::string &title);

    bool moveSongDown(const std::string &title);

    bool skipToNextSong();

    bool skipToPreviousSong();

    bool setCurrentSongIndex(int index);

    Song *getCurrentSong();

    void resetToFirstSong();

    const std::string &getName() const;

    void setName(const std::string &newName);

    bool isEmpty() const;

    const std::vector<Song> &getSongs() const;
};

#endif
