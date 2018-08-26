#pragma once

#include "node.h"
#include "date.h"

#include <memory>
#include <iostream>

using namespace std;

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();
