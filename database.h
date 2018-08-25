//
// Created by a.magomedov on 25.08.2018.
//

#ifndef C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H
#define C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H

#include "date.h"

#include <vector>
#include <iostream>

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os);

    template<typename L>
    int RemoveIf(const L predicate);

    template<typename L>
    std::vector<std::string> FindIf(const L predicate);

    std::string Last(const Date& date);
};


#endif //C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATABASE_H
