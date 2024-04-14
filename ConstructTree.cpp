#include "ConstructTree.h"
#include "Node.h"
#include <cmath>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

vector<shared_ptr<Node>> ConstructTree(int timeStep, double initialStockPrice, double upFactor, double downFactor){
    double spotPrice = initialStockPrice;
    double upSize = upFactor;
    double downSize = downFactor;
    int steps = timeStep;

    int totalNodes = (steps + 1) * (steps + 2) / 2;
    vector<shared_ptr<Node>> tree;
    tree.reserve(totalNodes);

    // Add root node
    tree.push_back(make_shared<Node>(spotPrice, 0.0, 0));

    for (int i = 1; i <= steps; ++i) {
        for (int k = 0; k <= i; ++k) {
            double stockPrice = spotPrice * pow(upSize, i-k) * pow(downSize, k);
            tree.push_back(make_shared<Node>(stockPrice, 0.0, i));
        }
    }

    // Linking nodes
    int index = 0;
    for (int level = 0; level < steps; ++level) {
        for (int position = 0; position <= level; ++position) {
            shared_ptr<Node> currentNode = tree[index];
            if (position <= level) {
                currentNode->upChild = tree[index + level + 1];
                currentNode->downChild = tree[index + level + 2];
            }
            index++;
        }
    }
    return tree;
}