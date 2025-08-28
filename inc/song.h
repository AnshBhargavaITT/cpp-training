#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
    std::string title;
    std::string duration;
    std::string filePath;

public:
    Song(const std::string &title, const std::string &duration, const std::string &filePath);

    std::string getTitle() const;

    std::string getDuration() const;

    std::string getFilePath() const;

    void setDuration(const std::string &duration);

    bool operator==(const Song &other) const;
};

#endif
