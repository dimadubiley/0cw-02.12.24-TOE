#pragma once
template<typename T>
class Tree
{
    class Node
    {
    public:
        T value;
        Node* left;
        Node* right;
        Node(T value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, T value);
    void print(Node* node) const;
    void clear(Node* node);
    Node* erase(Node* node, T key);

public:
    Tree() : root(nullptr) {}
    Tree(const Tree& other);
    Tree& operator=(const Tree& other);
    ~Tree();

    void insert(T value);
    void print() const;
    void erase(T key);
};
