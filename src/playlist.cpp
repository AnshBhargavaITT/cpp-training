#include "playlist.h"
#include <iostream>
#include <algorithm>

Playlist::Playlist() : playlistName(""), songs(), songIterator(songs.end()) {}

Playlist::Playlist(const std::string &name) : playlistName(name), songs(), songIterator(songs.end()) {}

bool Playlist::addSong(const Song &song)
{
    for (std::vector<Song>::iterator songsIterator = songs.begin(); songsIterator != songs.end(); songsIterator++)
    {
        if (*songsIterator == song)
        {
            std::cout << "Song already exists in playlist: " << song.getTitle() << std::endl;
            return false;
        }
    }

    songs.push_back(song);

    if (songs.size() == 1) { songIterator = songs.begin(); }

    return true;
}

bool Playlist::moveSongUp(const std::string &title)
{
    for (std::vector<Song>::iterator songsIterator = songs.begin(); songsIterator != songs.end(); songsIterator++)
    {
        if (songsIterator->getTitle() == title && songsIterator != songs.begin())
        {
            std::iter_swap(songsIterator, songsIterator - 1);

            if (songIterator == songsIterator) { songIterator--; }

            else if (songIterator == songsIterator - 1) { songIterator++; }

            return true;
        }
    }

    std::cout << "Cannot move song up: " << title << std::endl;
    return false;
}

bool Playlist::moveSongDown(const std::string &title)
{
    for (std::vector<Song>::iterator songsIterator = songs.begin(); songsIterator != songs.end(); songsIterator++)
    {
        if (songsIterator->getTitle() == title && songsIterator + 1 != songs.end())
        {
            std::iter_swap(songsIterator, songsIterator + 1);

            if (songIterator == songsIterator) { songIterator++; }

            else if (songIterator == songsIterator + 1) { songIterator--; }

            return true;
        }
    }

    std::cout << "Cannot move song down: " << title << std::endl;
    return false;
}

bool Playlist::skipToNextSong()
{
    if (songs.empty() || songIterator + 1 == songs.end())
    {
        std::cout << "No next song to skip to" << std::endl;
        return false;
    }

    ++songIterator;
    return true;
}

bool Playlist::skipToPreviousSong()
{
    if (songs.empty() || songIterator == songs.begin())
    {
        std::cout << "No previous song to skip to" << std::endl;
        return false;
    }

    --songIterator;
    return true;
}

Song *Playlist::getCurrentSong()
{
    if (songs.empty() || songIterator == songs.end()) { return nullptr; }
    
    return &(*songIterator);
}

void Playlist::resetToFirstSong() { songIterator = songs.begin(); }

const std::string &Playlist::getName() const { return playlistName; }

bool Playlist::isEmpty() const { return songs.empty(); }

const std::vector<Song> &Playlist::getSongs() const { return songs; }

void Playlist::setName(const std::string &newName) { playlistName = newName; }

bool Playlist::setCurrentSongIndex(int index)
{
    if (index < 0 || index >= songs.size())
    {
        std::cout << "Invalid song index: " << index << std::endl;
        return false;
    }

    songIterator = songs.begin() + index;
    return true;
}

bool Playlist::removeSong(const std::string &title)
{
    for (std::vector<Song>::iterator songsIterator = songs.begin(); songsIterator != songs.end(); songsIterator++)
    {
        if (songsIterator->getTitle() == title)
        {
            if (songIterator == songsIterator)
            {
                if (songIterator + 1 != songs.end())
                {
                    songIterator = songIterator + 1;
                }

                else if (songIterator != songs.begin())
                {
                    songIterator = songIterator - 1;
                }

                else
                {
                    songIterator = songs.end();
                }
            }

            else if (songIterator > songsIterator)
            {
                songIterator--;
            }

            songs.erase(songsIterator);

            return true;
        }
    }

    std::cout << "Song not found to remove: " << title << std::endl;

    return false;
}
