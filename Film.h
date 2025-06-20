#pragma once
#include "MediaItem.h"

// Film adds a duration (in minutes)
class Film : public MediaItem {
private:
    int duration;
	std::string type = "film"; // Type of media item
public:
    Film(int id,
        const std::string& director,  // stored in MediaItem::author
        const std::string& title,
        int year,
        int duration,
        int totalCopies,
        const std::string& location);
	std::string getType() const { return type; } // Returns the type of media item
    std::string serialize() const override;
};
