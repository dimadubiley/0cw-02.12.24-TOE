#include "Tree.h"
#include <iostream>
using namespace std;

void Tree::insert(Node* node, int value)
{
	if (!node) return;

	if (value > node->value)
	{
		insert(node->right, value);
	}
	else if (value < node->value)
	{
		insert(node->left, value);
	}
}

void Tree::print(Node* Node) const
{
	if (!Node) return;

	print(Node->left);
	print(Node->right);
	cout << Node->value << " ";
}

void Tree::insterd(int value)
{
	if (root == nullptr) root = new Node(value);

	insert (root, value);
}

void Tree::print() const
{
	print(root);
}
