#include "MediaItem.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

// Konstruktor
MediaItem::MediaItem(int id, const std::string& author, const std::string& title, int year,
    int totalCopies, const std::string& location)
    : id(id), author(author), title(title), year(year), totalCopies(totalCopies),
    availableCopies(totalCopies), location(location), holder_id(NULL) {
}

// Gettery
int MediaItem::getId() const { return id; }
const std::string& MediaItem::getAuthor() const { return author; }
const std::string& MediaItem::getTitle() const { return title; }

// Operacja wypozyczenia - zmniejszenie liczby dostepnych egzemplarzy
void MediaItem::checkOut(int borrower) {
    if (availableCopies <= 0) throw std::runtime_error("Brak dostepnych egzemplarzy");
    availableCopies--;
    holder_id = borrower;
}

// Operacja zwrotu - zwiekszenie liczby dostepnych egzemplarzy
void MediaItem::returnItem() {
    if (availableCopies >= totalCopies) throw std::runtime_error("Brak wypozyczonych egzemplarzy");
    availableCopies++;
    holder_id = NULL;
}

// Ustawianie liczby dostepnych egzemplarzy (uzywane przy ladowaniu z pliku)
void MediaItem::setAvailableCopies(int avail) { availableCopies = avail; }

// Ustawianie informacji o wypozyczajacym (uzywane przy ladowaniu z pliku)
void MediaItem::setHolder(int h) { holder_id = h; }

// Wyswietlanie obiektu w formacie CSV rozszerzonym
std::ostream& operator<<(std::ostream& os, const MediaItem& item) {
    os << item.id << ", " << item.author << ", " << item.title
        << ", " << item.year << ", "<< ", " << item.totalCopies << ", " << item.availableCopies
        << ", " << item.location << ", " << (item.holder_id == NULL ? "-" : std::to_string(item.holder_id));
    return os;
}