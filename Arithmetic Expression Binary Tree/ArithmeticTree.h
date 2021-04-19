#pragma once
#include "Node.h"
class ArithmeticTree
{
private:
	Node* head = nullptr;
public:
	ArithmeticTree(std::string str);
	~ArithmeticTree();
	int calculate();
};