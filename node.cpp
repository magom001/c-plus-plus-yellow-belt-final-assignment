//
// Created by a.magomedov on 25.08.2018.
//

#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const std::string &event) {
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) {
    switch(comparison_) {
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) {
    switch(comparison_) {
        case Comparison::Equal:
            return event == event_;
        case Comparison::NotEqual:
            return event != event_;
        case Comparison::Greater:
            return event > event_;
        case Comparison::GreaterOrEqual:
            return event >= event_;
        case Comparison::Less:
            return event < event_;
        case Comparison::LessOrEqual:
            return event <= event_;
    }
}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) {
    switch(logical_op_) {
        case LogicalOperation::Or:
            return node1_->Evaluate(date, event) || node2_->Evaluate(date, event);
        case LogicalOperation::And:
            return node1_->Evaluate(date, event) && node2_->Evaluate(date, event);
    }
}
