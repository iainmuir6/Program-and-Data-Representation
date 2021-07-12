// Iain Muir, iam9ez
// February 25th, 2020
// BinaryNode.cpp

#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
