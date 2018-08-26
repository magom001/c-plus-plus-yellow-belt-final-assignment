//
// Created by a.magomedov on 25.08.2018.
//

#include "database.h"

std::ostream& operator<<(std::ostream& os, const Entry& entry) {
    os << entry.date << " " << entry.event;
}

void Database::Add(const Date &date, const std::string &event) {
    // if there are already events for the given date
    if(storage.count(date)) {
        // if the given event is not scheduled for the given date
        if(std::find(storage[date].begin(), storage[date].end(), event) == storage[date].end()) {
            // add it
            storage[date].push_back(event);
        }
        // if there are no events for the given date
    } else {
        // just add the event
        storage[date].push_back(event);
    }
}

void Database::Print(std::ostream &os) const {
    for(auto date_it = storage.begin(); date_it != storage.end(); date_it = std::next(date_it)) {
       for(auto event_it = (*date_it).second.begin(); event_it != (*date_it).second.end(); event_it = std::next(event_it)) {
            os << (*date_it).first << " " << (*event_it) << "\n";
       }
    }
}

std::string Database::Last(const Date &date) const {
    auto it = storage.upper_bound(date);

    // if date is not smaller than other dates in the storage
    if(it != storage.begin()) {
        return (*std::prev(it)).first.ToString() + " " + (*std::prev(it)).second.back();
    } else {
        return "No entries";
    }

}


