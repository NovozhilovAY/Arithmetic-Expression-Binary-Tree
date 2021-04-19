#include "Node.h"

Node::Node(const std::string& str)
{
	if (str.size() == 1)
	{
		val = std::stoi(str);
		return;
	}
	int operat_pos = find_pos_of_min_priority(str);
	operation = str[operat_pos];
	std::string str_left = divide_str(0, operat_pos, str);
	std::string str_right = divide_str(operat_pos + 1, str.size(), str);
	left = new Node(str_left);
	right = new Node(str_right);
}

int Node::calculate(Node* n)
{
	if (n->operation == '\0')
	{
		return n->val;
	}
	int res;
	switch (n->operation)
	{
	case'+':
		res = calculate(n->left) + calculate(n->right);
		break;
	case'-':
		res = calculate(n->left) - calculate(n->right);
		break;
	case'*':
		res = calculate(n->left) * calculate(n->right);
		break;
	case'/':
		res = calculate(n->left) / calculate(n->right);
		break;
	}
	return res;
}

bool Node::is_operator(const char& ch)const
{
	std::string operators = "+-*/";
	for (int i = 0; i < operators.size(); i++)
	{
		if (operators[i] == ch)
		{
			return true;
		}
	}
	return false;
}
std::string Node::divide_str(int left_pos, int right_pos, const std::string& str)const
{
	std::string res = "";
	for (int i = left_pos; i < right_pos; i++)
	{
		res += str[i];
	}
	return res;
}
void Node::free_tree(Node* n)
{
	if (n->left)
	{
		free_tree(n->left);
	}
	if (n->right)
	{
		free_tree(n->right);
	}
	delete n;
}

int Node::find_pos_of_min_priority(std::string str)const
{
	int pos = -1;
	int min_priority = 5;
	for (int i = 0; i < str.size(); i++)
	{
		if (is_operator(str[i]))
		{
			if (priority[str[i]] < min_priority)
			{
				pos = i;
				min_priority = priority[str[i]];
			}
		}
	}
	if (pos == -1)
	{
		throw std::logic_error("Str doesn't have operator");
	}
	return pos;
}