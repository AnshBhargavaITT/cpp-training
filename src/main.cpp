#include <iostream>
#include "ui.h"

int main()
{
    MusicPlayer player;
    if (!player.loadFromFile("playlists.txt"))
    {
        std::cout << "Starting with empty library" << std::endl;
    }

    bool running = true;
    bool hasChanges = false;

    while (running)
    {
        int choice;
        do
        {
            choice = displayMenuAndGetCommand(player);
            if (choice == -1)
            {
                std::cout << "Invalid option" << std::endl;
            }
        } while (choice == -1);

        switch (choice)
        {
        case CREATE_PLAYLIST:
            if (createPlaylist(player))
            {
                hasChanges = true;
            }
            break;

        case ADD_SONG:
            if (addSongToPlaylist(player))
            {
                hasChanges = true;
            }
            break;

        case SELECT_PLAYLIST:
            selectPlaylist(player);
            break;

        case PLAY_SONG:
            selectAndPlaySong(player);
            break;

        case PAUSE:
            player.pauseCurrentSong();
            break;

        case NEXT:
            player.playNextSong();
            break;

        case PREV:
            player.playPreviousSong();
            break;

        case MOVE_UP:
            if (moveSongUp(player))
            {
                hasChanges = true;
            }
            break;

        case MOVE_DOWN:
            if (moveSongDown(player))
            {
                hasChanges = true;
            }
            break;

        case SHOW_PLAYLIST:
            showCurrentPlaylist(player);
            break;

        case RENAME_PLAYLIST:
            if (renamePlaylist(player))
            {
                hasChanges = true;
            }
            break;

        case DELETE_PLAYLIST:
            if (deletePlaylist(player))
            {
                hasChanges = true;
            }
            break;

        case DELETE_SONG:
            if (deleteSongFromPlaylist(player))
            {
                hasChanges = true;
            }
            break;

        case QUIT:
            quit(player, running, hasChanges);
            break;

        default:
            std::cout << "Invalid option" << std::endl;
            break;
        }

        if (hasChanges && choice != QUIT)
        {
            player.saveToFile("playlists.txt");
            hasChanges = false;
        }
    }

    return 0;
}
