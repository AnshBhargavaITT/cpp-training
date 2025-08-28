#include <string>
#include <SFML/Audio.hpp>

std::string getDurationFromFile(const std::string &filepath)
{
    sf::Music music;

    if (!music.openFromFile(filepath))
    {
        return "0:00";
    }

    sf::Time duration = music.getDuration();

    int totalSeconds = duration.asSeconds();

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}

int atoi(const std::string &input)
{
    int result = 0;
    for (int inputIterator = 0; inputIterator < input.length(); inputIterator++)
    {
        if (!std::isdigit(input[inputIterator])) { return -1;}

        result = result * 10 + (input[inputIterator] - '0');
    }
    return result;
}