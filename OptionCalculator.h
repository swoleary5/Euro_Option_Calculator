#pragma once

#include "Node.h"
#include <memory>

double
calculateNodeValues(std::shared_ptr<Node> currNode, double discount, double upProb, double downProb, double strike, char optionType);

