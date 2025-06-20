#pragma once
#include "MediaItem.h"

// Magazine adds issue number and periodicity
class Magazine : public MediaItem {
private:
    int issueNumber;
	std::string type = "magazine"; // Type of media item
public:
    Magazine(int id,
        const std::string& author,
        const std::string& title,
        int year,
        int issueNumber,
        int totalCopies,
        const std::string& location);
	std::string getType() const { return type; } // Returns the type of media item

    std::string serialize() const override;
};
