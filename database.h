//
// Created by a.magomedov on 25.08.2018.
//

#ifndef C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H
#define C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H

#include "date.h"

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


struct Entry {
    Date date;
    std::string event;
};

std::ostream& operator<<(std::ostream& os, const Entry& entry);

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;

    template<typename L>
    int RemoveIf(const L predicate) {
        // init deleted events counter
        int count = 0;

        // iterated over each date in the storage
        for(auto date_it = storage.begin(); date_it != storage.end();) {

            // for each date iterate over each event
            for(auto event_it = (*date_it).second.begin(); event_it != (*date_it).second.end();) {

                // if predicate returns true for the date-event pair
                if(predicate((*date_it).first, (*event_it))) {
                    // remove event from the storage
                    event_it = storage[(*date_it).first].erase(event_it);

                    // increase the count by 1
                    ++count;
                } else {
                    // if not move the iterator to the next event
                    event_it = next(event_it);
                }
            }
            // if no more events for the given date, remove the date from storage
            if((*date_it).second.size() == 0) {
                date_it = storage.erase(date_it);
            } else {
                date_it = next(date_it);
            }
        }

        return count;
    }

    template<typename L>
    std::vector<Entry> FindIf(const L predicate) const {
        std::vector<Entry> output;
        for(auto date_it = storage.begin(); date_it != storage.end(); date_it = std::next(date_it)) {
            for(auto event_it = (*date_it).second.begin(); event_it != (*date_it).second.end(); event_it = next(event_it)) {
                if(predicate((*date_it).first, (*event_it))) {
                    output.push_back({(*date_it).first, (*event_it)});
                }
            }
        }

        return output;
    }


    std::string Last(const Date& date) const;

private:
    std::map<Date, std::vector<std::string>> storage;
};


#endif //C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H
