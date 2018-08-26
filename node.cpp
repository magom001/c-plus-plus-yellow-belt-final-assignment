//
// Created by a.magomedov on 25.08.2018.
//

#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const std::string &event) {
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) {
    return false;
}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) {
    return false;
}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) {
    return false;
}

bool Node::Evaluate(const Date &date, const std::string &event) {
    return false;
}
