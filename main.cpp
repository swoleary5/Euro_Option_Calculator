// main.cpp
#include <iostream>
#include <memory>
#include <cmath>
#include "Node.h"
#include "ConstructTree.h"
#include "OptionCalculator.h"

using namespace std;

int main() {
    double T = 0.4167;
    int numSteps = 20;
    double dt = T / numSteps;
    double s0 = 50;
    double r = 0.1;
    double strike = 50;
    double sigma = 0.4;

    double upFactor = exp(sigma * sqrt(dt));
    double downFactor = 1 / upFactor;
    double discountFactor = exp(-r * dt);
    double upProb = (1 / discountFactor - downFactor) / (upFactor - downFactor);
    double downProb = 1 - upProb;

    auto root = ConstructTree(numSteps, s0, upFactor, downFactor);

    /*
    Check for proper tree construction
    cout << "Nodes in the Tree:" << endl;
    for (const auto& node : root) {
        if (node) {  // Check if the shared_ptr is not null
            cout << "Node Stock Price: " << node->stockPrice << endl;
            if (node->downChild) {
                cout << "Down Child Stock Price: " << node -> downChild -> stockPrice << endl; 
                cout << "Up Child: " << node -> upChild -> stockPrice << endl;
            } else {
                cout << "None" << endl; 
            }
        } else {
            cout << "Node is null" << endl;
        }
    }
    */

    char optionType = 'c'; // 'c' for call, 'p' for put
    double optionValue = calculateNodeValues(root[0], discountFactor, upProb, downProb, strike, optionType);
    cout << '\n' << optionValue;
    return 0;
}
