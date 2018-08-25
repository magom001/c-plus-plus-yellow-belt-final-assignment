//
// Created by a.magomedov on 25.08.2018.
//

#ifndef C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H
#define C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H

#include <iostream>
#include <string>
class Date {

};

Date ParseDate(std::istringstream& is);

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif //C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H
