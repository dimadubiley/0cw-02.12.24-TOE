#pragma once
class Tree
{
	class Node
	{
	public:
		int value;
		Node* left;
		Node* right;
		Node()
			: value(0), left(nullptr), right(nullptr) {}
		Node(int value) : value(0), left(nullptr), right(nullptr) {}
	};
	Node* root;
	void insert(Node* node, int value);
	void print(Node* Node) const;
public:
	Tree() : root(nullptr) {}
	void insterd(int value);
	void print() const;
};