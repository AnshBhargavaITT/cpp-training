#include <ui.h>
#include <iostream>
#include <utility.h>

void showCurrentPlaylist(const MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();

    if (!currentPlaylist || currentPlaylist->isEmpty())
    {
        std::cout << "Playlist is empty" << std::endl;
        return;
    }

    std::cout << "Current Playlist: " << currentPlaylist->getName() << std::endl;
    const std::vector<Song> &songs = currentPlaylist->getSongs();

    for (int songsIterator = 0; songsIterator < songs.size(); songsIterator++)
    {
        const Song &song = songs[songsIterator];
        std::cout << (songsIterator + 1) << ". " << song.getTitle() << " (" << song.getDuration() << ")" << std::endl;
    }
}

std::string choosePlaylist(const MusicPlayer &player, const std::string &prompt)
{
    const std::map<std::string, Playlist> &playlists = player.getAllPlaylists();

    if (playlists.empty())
    {
        std::cout << "No playlists available" << std::endl;
        return "";
    }

    std::cout << prompt << std::endl;

    std::vector<std::string> playlistNames;

    for (std::map<std::string, Playlist>::const_iterator iteratorI = playlists.begin(); iteratorI != playlists.end(); iteratorI++)
    {
        playlistNames.push_back(iteratorI->first);
    }

    for (int playlistIterator = 0; playlistIterator < playlistNames.size(); playlistIterator++)
    {
        std::cout << (playlistIterator + 1) << ". " << playlistNames[playlistIterator] << std::endl;
    }

    std::cout << "Enter your choice: " << std::endl;
    std::string input;
    std::getline(std::cin, input);

    for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
    {
        if (!std::isdigit(input[inputIterator]))
        {
            std::cout << "Invalid choice" << std::endl;
            return "";
        }
    }

    int choice = 0;

    for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
    {
        choice = choice * 10 + (input[inputIterator] - '0');
    }

    if (choice >= 1 && choice <= playlistNames.size())
    {
        return playlistNames[choice - 1];
    }

    std::cout << "Invalid choice" << std::endl;
    return "";
}

bool createPlaylist(MusicPlayer &player)
{
    std::string playlistName;
    std::cout << "Enter new playlist name: " << std::endl;
    std::getline(std::cin, playlistName);

    if (player.createPlaylist(playlistName))
    {
        std::cout << "Playlist created successfully" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Playlist already exists" << std::endl;
        return false;
    }
}

bool addSongToPlaylist(MusicPlayer &player)
{
    std::string playlistName = choosePlaylist(player, "Select playlist to add song to:");

    if (playlistName.empty()) { return false; }

    std::string songTitle;
    std::string filePath;
    std::cout << "Enter song title: " << std::endl;
    std::getline(std::cin, songTitle);
    std::cout << "Enter file path: " << std::endl;
    std::getline(std::cin, filePath);
    std::string duration = getDurationFromFile(filePath);

    Song song(songTitle, duration, filePath);

    if (player.addSongToPlaylist(playlistName, song))
    {
        std::cout << "Song added" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Failed to add song" << std::endl;
        return false;
    }
}

void playFirstSongInPlaylist(MusicPlayer &player, const Playlist *playlist)
{
    if (!playlist || playlist->isEmpty()) { return; }

    player.playSongAtIndex(0);
}

void selectPlaylist(MusicPlayer &player)
{
    std::string playlistName = choosePlaylist(player, "Select a playlist:");

    if (playlistName.empty()) { return; }

    if (player.selectActivePlaylist(playlistName))
    {
        std::cout << "Playlist selected: " << playlistName << std::endl;
        const Playlist *currentPlaylist = player.getActivePlaylist();
        playFirstSongInPlaylist(player, currentPlaylist);
        showCurrentPlaylist(player);
    }
    else
    {
        std::cout << "Failed to select playlist" << std::endl;
    }
}

bool moveSongUp(MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();

    if (!currentPlaylist)
    {
        std::cout << "No playlist selected" << std::endl;
        return false;
    }

    const std::vector<Song> &songs = currentPlaylist->getSongs();
    if (songs.empty())
    {
        std::cout << "Current playlist is empty" << std::endl;
        return false;
    }

    std::cout << "Select song to move up:" << std::endl;

    for (int songsIterator = 0; songsIterator < songs.size(); songsIterator++)
    {
        std::cout << (songsIterator + 1) << ". " << songs[songsIterator].getTitle() << std::endl;
    }
    std::cout << "Enter your choice: " << std::endl;

    std::string input;
    std::getline(std::cin, input);
    int choice = atoi(input);

    if (choice < 1 || choice > songs.size())
    {
        std::cout << "Invalid song number" << std::endl;
        return false;
    }

    const std::string &songTitle = songs[choice - 1].getTitle();

    if (!player.moveSongUpInPlaylist(currentPlaylist->getName(), songTitle))
    {
        return false;
    }

    return true;
}

bool moveSongDown(MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();

    if (!currentPlaylist)
    {
        std::cout << "No playlist selected" << std::endl;
        return false;
    }

    const std::vector<Song> &songs = currentPlaylist->getSongs();

    if (songs.empty())
    {
        std::cout << "Current playlist is empty" << std::endl;
        return false;
    }

    std::cout << "Select song to move down:" << std::endl;

    for (int iteratorI = 0; iteratorI < songs.size(); iteratorI++)
    {
        std::cout << (iteratorI + 1) << ". " << songs[iteratorI].getTitle() << std::endl;
    }
    std::cout << "Enter your choice : " << std::endl;

    std::string input;
    std::getline(std::cin, input);
    int choice = atoi(input);

    if (choice < 1 || choice > songs.size())
    {
        std::cout << "Invalid song number" << std::endl;
        return false;
    }

    const std::string &songTitle = songs[choice - 1].getTitle();

    if (!player.moveSongDownInPlaylist(currentPlaylist->getName(), songTitle))
    {
        return false;
    }

    return true;
}

void selectAndPlaySong(MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();

    if (!currentPlaylist)
    {
        std::cout << "No playlist selected" << std::endl;
        return;
    }

    const std::vector<Song> &songs = currentPlaylist->getSongs();

    if (songs.empty())
    {
        std::cout << "Current playlist is empty" << std::endl;
        return;
    }

    std::cout << "Select a song to play:" << std::endl;

    for (int songsIterator = 0; songsIterator < songs.size(); songsIterator++)
    {
        std::cout << (songsIterator + 1) << ". " << songs[songsIterator].getTitle() << std::endl;
    }
    std::cout << "Enter your choice: " << std::endl;

    std::string input;
    std::getline(std::cin, input);
    int choice = atoi(input);

    if (choice < 1 || choice > songs.size())
    {
        std::cout << "Invalid song number" << std::endl;
        return;
    }

    player.playSongAtIndex(choice - 1);
}

int displayMenuAndGetCommand(const MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();
    const bool hasPlaylists = !player.getAllPlaylists().empty();
    const bool hasSelection = currentPlaylist != nullptr;
    const bool hasSongs = hasSelection && !currentPlaylist->isEmpty();

    std::map<int, Command> menuMap;
    int displayIndex = 1;

    std::cout << "Music Player Menu" << std::endl;

    menuMap[displayIndex] = CREATE_PLAYLIST;
    std::cout << displayIndex++ << " Create Playlist" << std::endl;

    if (hasPlaylists)
    {
        menuMap[displayIndex] = ADD_SONG;
        std::cout << displayIndex++ << " Add Song to Playlist" << std::endl;

        menuMap[displayIndex] = SELECT_PLAYLIST;
        std::cout << displayIndex++ << " Select Playlist" << std::endl;

        menuMap[displayIndex] = RENAME_PLAYLIST;
        std::cout << displayIndex++ << " Rename Playlist" << std::endl;

        menuMap[displayIndex] = DELETE_PLAYLIST;
        std::cout << displayIndex++ << " Delete Playlist" << std::endl;
    }

    if (hasSongs)
    {
        menuMap[displayIndex] = PLAY_SONG;
        std::cout << displayIndex++ << " Play Song" << std::endl;

        menuMap[displayIndex] = PAUSE;
        std::cout << displayIndex++ << " Pause Current Song" << std::endl;

        menuMap[displayIndex] = NEXT;
        std::cout << displayIndex++ << " Play Next Song" << std::endl;

        menuMap[displayIndex] = PREV;
        std::cout << displayIndex++ << " Play Previous Song" << std::endl;

        menuMap[displayIndex] = MOVE_UP;
        std::cout << displayIndex++ << " Move Song Up" << std::endl;

        menuMap[displayIndex] = MOVE_DOWN;
        std::cout << displayIndex++ << " Move Song Down" << std::endl;

        menuMap[displayIndex] = DELETE_SONG;
        std::cout << displayIndex++ << " Delete Song from Playlist" << std::endl;
    }

    if (hasSelection)
    {
        menuMap[displayIndex] = SHOW_PLAYLIST;
        std::cout << displayIndex++ << " Show Current Playlist" << std::endl;
    }

    menuMap[displayIndex] = QUIT;
    std::cout << displayIndex << " Quit" << std::endl;

    std::cout << "Enter choice: " << std::endl;
    std::string input;
    std::getline(std::cin, input);
    int selectedOption = atoi(input);

    if (menuMap.find(selectedOption) != menuMap.end())
    {
        return menuMap[selectedOption];
    }

    return -1;
}

void quit(MusicPlayer &player, bool &running, bool hasChanges)
{
    if (hasChanges)
    {
        std::cout << "You have unsaved changes , Save before exiting (y/n): " << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if (input == "y" || input == "Y")
        {
            player.saveToFile("playlists.txt");
            std::cout << "Changes saved" << std::endl;
        }
    }
    std::cout << "Exiting Music Player" << std::endl;
    running = false;
}

bool deletePlaylist(MusicPlayer &player)
{
    std::string playlistName = choosePlaylist(player, "Select a playlist to delete:");
    if (playlistName.empty()) { return false; }

    std::cout << "Are you sure you want to delete playlist " << playlistName << "(y/n): " << std::endl;
    std::string input;
    std::getline(std::cin, input);

    if (input == "y" || input == "Y")
    {
        if (player.deletePlaylist(playlistName))
        {
            std::cout << "Playlist deleted." << std::endl;
            return true;
        }
        else
        {
            std::cout << "Failed to delete playlist." << std::endl;
        }
    }
    return false;
}

bool renamePlaylist(MusicPlayer &player)
{
    std::string oldName = choosePlaylist(player, "Select playlist to rename:");
    if (oldName.empty()) { return false; }

    std::string newName;
    std::cout << "Enter new name for the playlist: " << std::endl;
    std::getline(std::cin, newName);

    if (player.renamePlaylist(oldName, newName)) { return true; }
    else
    {
        std::cout << "Failed to rename playlist" << std::endl;
        return false;
    }
}

bool deleteSongFromPlaylist(MusicPlayer &player)
{
    const Playlist *currentPlaylist = player.getActivePlaylist();

    if (!currentPlaylist)
    {
        std::cout << "No playlist selected" << std::endl;
        return false;
    }

    const std::vector<Song> &songs = currentPlaylist->getSongs();

    if (songs.empty())
    {
        std::cout << "Playlist is empty" << std::endl;
        return false;
    }

    std::cout << "Select song to delete:" << std::endl;

    for (int songsIterator = 0; songsIterator < songs.size(); songsIterator++)
    {
        std::cout << (songsIterator + 1) << ". " << songs[songsIterator].getTitle() << std::endl;
    }

    std::string input;
    std::getline(std::cin, input);
    int choice = atoi(input);

    if (choice < 1 || choice > songs.size())
    {
        std::cout << "Invalid song choice" << std::endl;
        return false;
    }

    const std::string &title = songs[choice - 1].getTitle();

    if (player.removeSongFromPlaylist(currentPlaylist->getName(), title))
    {
        return true;
    }
    else
    {
        std::cout << "Failed to delete song" << std::endl;
        return false;
    }
}
