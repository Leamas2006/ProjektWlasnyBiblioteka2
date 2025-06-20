#pragma once
#include "MediaItem.h"

// Klasa reprezentujaca ksiazke, dziedziczaca z MediaItem
class Book : public MediaItem {
private:
    std::string isbn;
    std::string publisher;
	std::string type = "book"; // Typ elementu medialnego
public:
    // Konstruktor
    Book(int id, const std::string& author, const std::string& title, int year,
        const std::string& isbn, const std::string& publisher,
        int totalCopies, const std::string& location);
	std::string getType() const override { return type; } // Zwraca typ elementu medialnego

    // Serializacja do formatu CSV
    virtual std::string serialize() const override;
};