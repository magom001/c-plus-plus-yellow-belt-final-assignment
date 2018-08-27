//
// Created by a.magomedov on 25.08.2018.
//

#include "date.h"
#include <utility>

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
           "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

std::string Date::ToString() const {
    stringstream ss;
    ss << *this;
    return ss.str();
}

Date ParseDate(std::istream& is) {
    std::string DATE;
    is >> DATE;
    int year, month, day;

    std::stringstream ss(DATE);

    ss >> year;
    ss.ignore(1);

    ss >> month;
    ss.ignore(1);

    ss >> day;

    return Date(year, month, day);
}

bool operator<(const Date &lhs, const Date &rhs) {
    // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
    // создадим вектор из года, месяца и дня для каждой даты и сравним их
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator<=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
};

bool operator==(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator!=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>=(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


