// OptionCalculator.cpp
#include "OptionCalculator.h"
#include <iostream>

using namespace std;

double calculateNodeValues(std::shared_ptr<Node> currNode, double discount, double upProb, double downProb, double strike, char optionType) {
    if(!currNode->upChild && !currNode ->downChild){
        if(optionType == 'c'){
            return max(0.0, (currNode -> stockPrice) - strike);
        }else{
            return max(0.0, strike - (currNode -> stockPrice));
        }
    }

    double upValue = 0.0, downValue = 0.0;
    if (currNode->upChild) {
        upValue = calculateNodeValues(currNode->upChild, discount, upProb, downProb, strike, optionType);
    }
    if (currNode->downChild) {
        downValue = calculateNodeValues(currNode->downChild, discount, upProb, downProb, strike, optionType);
    }
    /*
    Self Check

    cout << "Current Price: " << currNode -> stockPrice << endl;
    cout << "Up Value: " << upValue << endl;
    cout << "Down Value: " << downValue << endl;
    cout << endl;
    */

    double expectedValue = (upProb * upValue) + (downProb * downValue);
    return discount * expectedValue;
}

