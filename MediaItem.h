#pragma once
#include <string>
#include <ostream>

// Klasa bazowa reprezentujaca element medialny (np. ksiazka)
class MediaItem {
protected:
    int id;                     // Unikalny identyfikator
    std::string author;         // Autor
    std::string title;          // Tytul
    int year;                   // Rok wydania
    int totalCopies;            // Calkowita liczba egzemplarzy
    int availableCopies;        // Dostepne egzemplarze
    std::string location;       // Miejsce przechowywania
    int holder_id;         // Osoba, u ktorej jest ksiazka
public:
    // Konstruktor
    MediaItem(int id, const std::string& author, const std::string& title, int year,
        int totalCopies, const std::string& location);
    virtual ~MediaItem() {} // Wirtualny destruktor
    virtual std::string getType() const {}; // Wirtualna metoda do zwracania typu elementu medialnego
    // Serializacja do formatu CSV
    virtual std::string serialize() const = 0;

    // Metody dostepu
    int getId() const;
    const std::string& getAuthor() const;
    const std::string& getTitle() const;

    // Operacje wypozyczenia i zwrotu
    virtual void checkOut(int borrower);
    virtual void returnItem();

    // Ustawianie wartosci przy ladowaniu z pliku
    void setAvailableCopies(int avail);
    void setHolder(int h);

    // Wyswietlanie za pomoca operatora <<
    friend std::ostream& operator<<(std::ostream& os, const MediaItem& item);
};