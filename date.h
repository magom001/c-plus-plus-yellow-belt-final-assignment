//
// Created by a.magomedov on 25.08.2018.
//
#pragma once
#ifndef C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H
#define C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    std::string ToString() const;

private:
    int year;
    int month;
    int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);


// даты будут по умолчанию выводиться в нужном формате
std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istringstream& is);


#endif //C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_DATE_H
