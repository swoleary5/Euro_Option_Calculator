#pragma once

#include <memory>

using namespace std;

class Node {
    public:
        double stockPrice;
        double payoff;
        int timeStep;

        shared_ptr<Node> upChild;
        shared_ptr<Node> downChild;

        Node(double stockPrice = 0.0, double payoff = 0.0, int timeStep = 0, shared_ptr<Node> 
            upChild = nullptr, shared_ptr<Node> downChild = nullptr) : stockPrice(stockPrice), 
            payoff(payoff), timeStep(timeStep), upChild(upChild), downChild(downChild) {}
};
