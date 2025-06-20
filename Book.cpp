#include "Book.h"
#include <sstream>

// Konstruktor przekazujacy parametry do MediaItem
Book::Book(int id, const std::string& author, const std::string& title, int year,
    const std::string& isbn, const std::string& publisher,
    int totalCopies, const std::string& location)
    : MediaItem(id, author, title, year, totalCopies, location), isbn(isbn), publisher(publisher) {
}



// Serializacja ksiazki do formatu CSV (pola oddzielone srednikami)
std::string Book::serialize() const {
    std::ostringstream oss;
    oss << id << ";" << author << ";" << title << ";" << year << ";"
        << isbn << ";" << publisher << ";" << totalCopies << ";"
        << availableCopies << ";" << location << ";" << holder_id;
    return oss.str();
}