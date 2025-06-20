#include "Library.h"
#include "Book.h"
#include "Film.h"
#include "Magazine.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Konstruktor ustawiajacy nazwe pliku
Library::Library(const std::string& filename) : filename(filename) {}

// Ladowanie bazy danych z pliku CSV
void Library::load() {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Nie mozna otworzyc pliku: " + filename);
    items.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, ';')) parts.push_back(token);
        if (parts.size() >= 10) {
            int id = std::stoi(parts[0]);
            std::string author = parts[1];
            std::string title = parts[2];
            int year = std::stoi(parts[3]);
            std::string isbn = parts[4];
            std::string publisher = parts[5];
            int total = std::stoi(parts[6]);
            int avail = std::stoi(parts[7]);
            std::string location = parts[8];
            int holder = std::stoi(parts[9]);
            auto book = std::make_shared<Book>(id, author, title, year, isbn, publisher, total, location);
            book->setAvailableCopies(avail);
            book->setHolder(holder);
            items.push_back(book);
        }
    }
}

// Zapis bazy danych do pliku CSV
void Library::save() const {
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Nie mozna otworzyc pliku do zapisu: " + filename);
    for (std::size_t i = 0; i < items.size(); ++i) {
        const std::shared_ptr<MediaItem>& item = items[i];
        file << item->serialize() << "\n";
    }
}

// Generowanie przykladowych danych (automatycznie)
void Library::generateSampleData(int count) {
    items.clear();
    for (int i = 1; i <= count; ++i) {
        int year = 1980 + (i % 40);
        std::string author = "Author" + std::to_string(i);
        std::string title = "Title" + std::to_string(i);
        std::string isbn = "ISBN" + std::to_string(100000 + i);
        std::string publisher = "Publisher" + std::to_string((i % 5) + 1);
        int copies = (i % 5) + 1;
        std::string loc = "Shelf" + std::to_string((i % 10) + 1);
        items.push_back(std::make_shared<Book>(i, author, title, year, isbn, publisher, copies, loc));
    }
}

// Wyswietlanie wszystkich ksiazek
void Library::displayAll() const {
    for (auto& item : items) {
        std::cout << *item << std::endl;
    }
}

// Szukanie po tytule (zwraca wektor wynikow)
std::vector<std::shared_ptr<MediaItem>> Library::searchByTitle(const std::string& keyword) const {
    std::vector<std::shared_ptr<MediaItem>> result;
    for (auto& item : items) {
        if (item->getTitle().find(keyword) != std::string::npos)
            result.push_back(item);
    }
    return result;
}

// Szukanie po autorze
std::vector<std::shared_ptr<MediaItem>> Library::searchByAuthor(const std::string& keyword) const {
    std::vector<std::shared_ptr<MediaItem>> result;
    for (auto& item : items) {
        if (item->getAuthor().find(keyword) != std::string::npos)
            result.push_back(item);
    }
    return result;
}

// Dodawanie nowego elementu
void Library::addItem(std::shared_ptr<MediaItem> item) {
    items.push_back(item);
}

// Usuwanie ksiazki po ID
void Library::removeById(int id) {
    auto it = std::remove_if(items.begin(), items.end(),
        [id](const std::shared_ptr<MediaItem>& item) { return item->getId() == id; });
    if (it == items.end()) throw std::runtime_error("Nie znaleziono ksiazki o ID: " + std::to_string(id));
    items.erase(it, items.end());
}

// Wypozyczenie ksiazki
void Library::checkOut(int id, const std::string& borrower) {
    for (auto& item : items) {
        if (item->getId() == id) {
            item->checkOut(borrower);
            return;
        }
    }
    throw std::runtime_error("Nie znaleziono ksiazki o ID: " + std::to_string(id));
}

// Zwrot ksiazki
void Library::returnItem(int id) {
    for (auto& item : items) {
        if (item->getId() == id) {
            item->returnItem();
            return;
        }
    }
    throw std::runtime_error("Nie znaleziono ksiazki o ID: " + std::to_string(id));
}