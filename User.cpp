#include "User.h"
#include "Book.h"
#include "Film.h"
#include "Magazine.h"
#include <algorithm>
#include <stdexcept>

User::User(int id, const std::string& name)
    : id(id), name(name) {
}

int User::getId() const { return id; }
const std::string& User::getName() const { return name; }

bool User::canBorrow(const std::shared_ptr<MediaItem>& item) const {
    if ((int)borrowedItems.size() >= MAX_TOTAL) return false;

    int books = 0, films = 0, mags = 0;
    for (auto it : borrowedItems) {
        if ( it->getType() == "book")      ++books;
        else if (it->getType() == "film") ++films;
        else if (it->getType() == "magazine") ++mags;
    }

    if (item->getType() == "book")
        return books < MAX_BOOKS;
    if (item->getType() == "film")
        return films < MAX_FILMS;
    if (item->getType() == "magazine")
        return mags < MAX_MAGAZINES;

    return false;
}

void User::borrowItem(const std::shared_ptr<MediaItem>& item) {
    if (!canBorrow(item))
        throw std::runtime_error("User " + name + " has reached borrowing limit");
    borrowedItems.push_back(item);
}

void User::returnItem(int itemId) {
    auto it = std::find_if(
        borrowedItems.begin(), borrowedItems.end(),
        [itemId](auto& i) { return i->getId() == itemId; });
    if (it == borrowedItems.end())
        throw std::runtime_error("User " + name + " did not borrow item ID " + std::to_string(itemId));
    borrowedItems.erase(it);
}
