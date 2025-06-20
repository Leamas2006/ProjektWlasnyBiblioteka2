#include "Film.h"
#include <sstream>

Film::Film(int id,
    const std::string& director,
    const std::string& title,
    int year,
    int duration,
    int totalCopies,
    const std::string& location)
    : MediaItem(id, director, title, year, totalCopies, location)
    , duration(duration)
{
}

std::string Film::serialize() const {
    std::ostringstream oss;
    // CSV: id;director;title;year;duration;total;available;location;holder
    oss << id << ";"
        << author << ";"    // director
        << title << ";"
        << year << ";"
        << duration << ";"
        << totalCopies << ";"
        << availableCopies << ";"
        << location << ";"
        << holder_id;
    return oss.str();
}
