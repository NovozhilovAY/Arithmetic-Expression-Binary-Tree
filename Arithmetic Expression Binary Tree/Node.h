#pragma once
#include <map>
#include <stdexcept>
#include <string>

static std::map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

class Node
{
private:
	int val;
	char operation = '\0';
	Node* left = nullptr;
	Node* right = nullptr;
public:
	Node(const std::string& str);
	int calculate(Node* n);
	void free_tree(Node* n);
private:
	int find_pos_of_min_priority(std::string str)const;
	bool is_operator(const char& ch)const;
	std::string divide_str(int left_pos, int right_pos, const std::string& str)const;
};