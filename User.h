#pragma once
#include <string>
#include <vector>
//#include <memory>
#include "MediaItem.h"

class User {
private:
    int id;
    std::string name;
    std::vector<std::shared_ptr<MediaItem>> borrowedItems;

    static const int MAX_TOTAL = 10;
    static const int MAX_BOOKS = 10;
    static const int MAX_FILMS = 2;
    static const int MAX_MAGAZINES = 3;

public:
    User(int id, const std::string& name);

    int getId() const;
    const std::string& getName() const;

    // Check if this user can borrow one more of the given type
    bool canBorrow(const std::shared_ptr<MediaItem>& item) const;

    // Actually borrow / return
    void borrowItem(const std::shared_ptr<MediaItem>& item);
    void returnItem(int itemId);
};
