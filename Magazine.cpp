#include "Magazine.h"
#include <sstream>

Magazine::Magazine(int id,
    const std::string& author,
    const std::string& title,
    int year,
    int issueNumber,
    int totalCopies,
    const std::string& location)
    : MediaItem(id, author, title, year, totalCopies, location)
    , issueNumber(issueNumber)
{
}

std::string Magazine::serialize() const {
    std::ostringstream oss;
    // CSV: id;author;title;year;issue;periodicity;total;available;location;holder
    oss << id << ";"
        << author << ";"
        << title << ";"
        << year << ";"
        << issueNumber << ";"
        << totalCopies << ";"
        << availableCopies << ";"
        << location << ";"
        << holder_id;
    return oss.str();
}
