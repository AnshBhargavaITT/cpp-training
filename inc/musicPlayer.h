#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "playlist.h"
#include <map>
#include <string>
#include <SFML/Audio.hpp>

class MusicPlayer
{
    std::map<std::string, Playlist> playlists;
    std::string activePlaylistName;
    sf::Music musicPlayer;
    bool isPlaying;

public:
    MusicPlayer();

    bool createPlaylist(const std::string &playlistName);

    bool addSongToPlaylist(const std::string &playlistName, Song song);

    bool selectActivePlaylist(const std::string &playlistName);

    bool playCurrentSong();

    bool pauseCurrentSong();

    bool playNextSong();

    bool playPreviousSong();

    bool moveSongUpInPlaylist(const std::string &playlistName, const std::string &songTitle);

    bool moveSongDownInPlaylist(const std::string &playlistName, const std::string &songTitle);

    const Playlist *getActivePlaylist() const;

    const std::map<std::string, Playlist> &getAllPlaylists() const;

    bool playSongAtIndex(int index);

    bool deletePlaylist(const std::string &playlistName);

    bool removeSongFromPlaylist(const std::string &playlistName, const std::string &songTitle);

    bool renamePlaylist(const std::string &oldName, const std::string &newName);

    bool saveToFile(const std::string &filename);

    bool loadFromFile(const std::string &filename);

protected:
    virtual bool openAudioFile(const std::string &filepath);

    virtual void playAudio();

    virtual void pauseAudio();

    virtual void stopAudio();

    virtual sf::Music::Status getAudioStatus() const;
};

#endif
