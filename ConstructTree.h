#pragma once

#include <memory>
#include <vector>
#include "Node.h"


using namespace std;

// The function declaration
vector<shared_ptr<Node>>
ConstructTree(int timeStep, double initialStockPrice, double upFactor, double downFactor);
