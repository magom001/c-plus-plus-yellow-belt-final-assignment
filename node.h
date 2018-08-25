//
// Created by a.magomedov on 25.08.2018.
//

#ifndef C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_NODE_H
#define C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_NODE_H

#include "date.h"

#include <string>

enum class LogicalOperation {
    Or,
    And
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node {
public:
    bool Evaluate(const Date& date, const std::string& event);
};

class EmptyNode : public Node {};

class DateComparisonNode : public Node {};

class EventComparisonNode : public Node {};

class LogicalOperationNode : public Node{};

#endif //C_PLUS_PLUS_YELLOW_FINAL_ASSIGNMENT_NODE_H
