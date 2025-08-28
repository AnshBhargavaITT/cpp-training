#include "song.h"

Song::Song(const std::string &title, const std::string &duration, const std::string &filePath)
    : title(title), duration(duration), filePath(filePath) {}

std::string Song::getTitle() const { return title; }

std::string Song::getDuration() const { return duration; }

std::string Song::getFilePath() const { return filePath; }

void Song::setDuration(const std::string &duration) { this->duration = duration; }

bool Song::operator==(const Song &other) const { return title == other.title; }
