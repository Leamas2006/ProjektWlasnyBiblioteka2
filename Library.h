#pragma once
#include <vector>
#include <memory>
#include <string>
#include "MediaItem.h"
#include "User.h"

// Klasa reprezentujaca biblioteke, zarzadzajaca kolekcja MediaItem
class Library {
private:
    std::vector<std::shared_ptr<MediaItem>> items; // Lista elementow
    std::string filename;                           // Plik bazy danych
	std::vector<std::shared_ptr<User>> users; // Lista uzytkownikow
public:
    // Konstruktor przyjmujacy nazwe pliku
    Library(const std::string& filename);

    // Ladowanie i zapisywanie bazy
    void load();
    void save() const;

    // Generowanie przykladowych danych
    void generateSampleData(int count = 100);

    // Operacje na kolekcji
    void displayAll() const;
    std::vector<std::shared_ptr<MediaItem>> searchByTitle(const std::string& keyword) const;
    std::vector<std::shared_ptr<MediaItem>> searchByAuthor(const std::string& keyword) const;
    void addItem(std::shared_ptr<MediaItem> item);
    void removeById(int id);
    void checkOut(int id, const std::string& borrower);
    void returnItem(int id);

    void addUser(std::shared_ptr<User> user);
	std::shared_ptr<User> findUserById(int userid) const;
    void returnItem(int itemId, int userId);
};