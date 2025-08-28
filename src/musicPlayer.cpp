#include "musicPlayer.h"
#include <iostream>
#include "playlist.h"
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <utility.h>

MusicPlayer::MusicPlayer() : activePlaylistName(""), isPlaying(false) {}

bool MusicPlayer::createPlaylist(const std::string &playlistName)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator != playlists.end())
    {
        std::cout << "Playlist already exists: " << playlistName << std::endl;
        return false;
    }

    std::pair<std::string, Playlist> newPlaylist(playlistName, Playlist(playlistName));
    playlists.insert(newPlaylist);
    return true;
}

bool MusicPlayer::addSongToPlaylist(const std::string &playlistName, Song song)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    std::string duration = getDurationFromFile(song.getFilePath());
    song.setDuration(duration);
    return playlistIterator->second.addSong(song);
}

bool MusicPlayer::selectActivePlaylist(const std::string &playlistName)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    activePlaylistName = playlistName;
    playlistIterator->second.resetToFirstSong();
    isPlaying = false;
    stopAudio();
    return true;
}

bool MusicPlayer::playCurrentSong()
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(activePlaylistName);

    if (playlistIterator == playlists.end() || playlistIterator->second.isEmpty())
    {
        std::cout << "No active playlist or it's empty" << std::endl;
        return false;
    }

    Song *currentSong = playlistIterator->second.getCurrentSong();
    if (!currentSong)
    {
        std::cout << "No current song to play" << std::endl;
        return false;
    }

    if (!openAudioFile(currentSong->getFilePath()))
    {
        std::cout << "Failed to load audio file: " << currentSong->getFilePath() << std::endl;
        return false;
    }

    playAudio();
    isPlaying = true;

    std::cout << "Playing: " << currentSong->getTitle() << " | Duration: " << currentSong->getDuration() << std::endl;

    return true;
}

bool MusicPlayer::pauseCurrentSong()
{
    if (isPlaying)
    {
        pauseAudio();
        isPlaying = false;
        return true;
    }

    std::cout << "Player is not playing" << std::endl;
    return false;
}

bool MusicPlayer::playNextSong()
{
    if (activePlaylistName.empty())
    {
        std::cout << "No active playlist selected" << std::endl;
        return false;
    }

    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(activePlaylistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Active playlist not found" << std::endl;
        return false;
    }

    if (!playlistIterator->second.skipToNextSong())
    {
        std::cout << "No next song" << std::endl;
        return false;
    }

    return playCurrentSong();
}

bool MusicPlayer::playPreviousSong()
{
    if (activePlaylistName.empty())
    {
        std::cout << "No active playlist selected" << std::endl;
        return false;
    }

    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(activePlaylistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Active playlist not found" << std::endl;
        return false;
    }

    if (!playlistIterator->second.skipToPreviousSong())
    {
        std::cout << "No previous song" << std::endl;
        return false;
    }

    return playCurrentSong();
}

bool MusicPlayer::moveSongUpInPlaylist(const std::string &playlistName, const std::string &songTitle)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    return playlistIterator->second.moveSongUp(songTitle);
}

bool MusicPlayer::moveSongDownInPlaylist(const std::string &playlistName, const std::string &songTitle)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    return playlistIterator->second.moveSongDown(songTitle);
}

const Playlist *MusicPlayer::getActivePlaylist() const
{
    std::map<std::string, Playlist>::const_iterator playlistIterator = playlists.find(activePlaylistName);

    if (playlistIterator != playlists.end())
    {
        return &playlistIterator->second;
    }

    return nullptr;
}

const std::map<std::string, Playlist> &MusicPlayer::getAllPlaylists() const { return playlists; }

bool MusicPlayer::playSongAtIndex(int index)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(activePlaylistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "No active playlist selected" << std::endl;
        return false;
    }

    Playlist *activePlaylist = &playlistIterator->second;

    if (index < 0 || index >= activePlaylist->getSongs().size())
    {
        std::cout << "Invalid song index" << std::endl;
        return false;
    }

    if (!activePlaylist->setCurrentSongIndex(index))
    {
        std::cout << "Failed to set current song index" << std::endl;
        return false;
    }

    Song *songToPlay = activePlaylist->getCurrentSong();

    if (!songToPlay)
    {
        std::cout << "No song found at current position" << std::endl;
        return false;
    }

    if (getAudioStatus() == sf::Music::Playing)
    {
        stopAudio();
    }

    if (!openAudioFile(songToPlay->getFilePath()))
    {
        std::cout << "Failed to open audio file: " << songToPlay->getFilePath() << std::endl;
        return false;
    }

    playAudio();
    isPlaying = true;

    std::cout << "Playing: " << songToPlay->getTitle() << " | Duration: " << songToPlay->getDuration() << std::endl;

    return true;
}

bool MusicPlayer::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);

    if (!file.is_open()) { return false; }

    const std::map<std::string, Playlist> &playlists = getAllPlaylists();
    file << playlists.size() << std::endl;

    std::map<std::string, Playlist>::const_iterator playlistIteratorI;

    for (playlistIteratorI = playlists.begin(); playlistIteratorI != playlists.end(); playlistIteratorI++)
    {
        const std::string &playlistName = playlistIteratorI->first;
        const Playlist &playlist = playlistIteratorI->second;

        file << playlistName << std::endl;
        const std::vector<Song> &songs = playlist.getSongs();
        file << songs.size() << std::endl;

        for (int songsIterator = 0; songsIterator < songs.size(); songsIterator++)
        {
            const Song &song = songs[songsIterator];
            file << song.getTitle() << std::endl;
            file << song.getDuration() << std::endl;
            file << song.getFilePath() << std::endl;
        }
    }

    file.close();
    return true;
}

bool MusicPlayer::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) { return false; }

    int playlistCount = 0;
    file >> playlistCount;
    file.ignore();

    for (int playlistIterator = 0; playlistIterator < playlistCount; playlistIterator++)
    {
        std::string playlistName;
        std::getline(file, playlistName);

        int songCount = 0;
        file >> songCount;
        file.ignore();

        createPlaylist(playlistName);

        for (int songIterator = 0; songIterator < songCount; songIterator++)
        {
            std::string title;
            std::string duration;
            std::string path;

            std::getline(file, title);
            std::getline(file, duration);
            std::getline(file, path);

            Song song(title, duration, path);
            addSongToPlaylist(playlistName, song);
        }
    }

    file.close();
    return true;
}

bool MusicPlayer::deletePlaylist(const std::string &playlistName)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    playlists.erase(playlistIterator);

    if (activePlaylistName == playlistName)
    {
        activePlaylistName = "";
        stopAudio();
        isPlaying = false;
    }

    std::cout << "Deleted playlist: " << playlistName << std::endl;
    return true;
}

bool MusicPlayer::removeSongFromPlaylist(const std::string &playlistName, const std::string &songTitle)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(playlistName);

    if (playlistIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << playlistName << std::endl;
        return false;
    }

    bool removed = playlistIterator->second.removeSong(songTitle);
    if (!removed)
    {
        std::cout << "Song not found in playlist: " << songTitle << std::endl;
        return false;
    }

    if (playlistName == activePlaylistName)
    {
        stopAudio();
        isPlaying = false;
    }

    std::cout << "Removed song '" << songTitle << "' from playlist '" << playlistName << "'" << std::endl;
    return true;
}

bool MusicPlayer::renamePlaylist(const std::string &oldName, const std::string &newName)
{
    std::map<std::string, Playlist>::iterator playlistIterator = playlists.find(newName);

    if (playlistIterator != playlists.end())
    {
        std::cout << "Playlist with the new name already exists: " << newName << std::endl;
        return false;
    }

    std::map<std::string, Playlist>::iterator oldIterator = playlists.find(oldName);

    if (oldIterator == playlists.end())
    {
        std::cout << "Playlist not found: " << oldName << std::endl;
        return false;
    }

    Playlist playlistToRename = oldIterator->second;
    playlists.erase(oldIterator);
    playlistToRename.setName(newName);
    playlists.insert(std::pair<std::string, Playlist>(newName, playlistToRename));

    if (activePlaylistName == oldName)
    {
        activePlaylistName = newName;
    }

    std::cout << "Playlist renamed from " << oldName << " to " << newName << std::endl;
    return true;
}

bool MusicPlayer::openAudioFile(const std::string &filepath) { return musicPlayer.openFromFile(filepath); }

void MusicPlayer::playAudio() { musicPlayer.play(); }

void MusicPlayer::pauseAudio() { musicPlayer.pause(); }

void MusicPlayer::stopAudio() { musicPlayer.stop(); }

sf::Music::Status MusicPlayer::getAudioStatus() const { return musicPlayer.getStatus(); }
