#include "Tree.h"
#include <iostream>
using namespace std;

template<typename T>
void Tree<T>::insert(Node*& node, T value)
{
    if (!node)
    {
        node = new Node(value);
        return;
    }

    if (value > node->value)
        insert(node->right, value);
    else if (value < node->value)
        insert(node->left, value);
}

template<typename T>
void Tree<T>::print(Node* node) const
{
    if (!node) return;

    print(node->left);
    cout << node->value << " ";
    print(node->right);
}

template<typename T>
void Tree<T>::clear(Node* node)
{
    if (!node) return;

    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::erase(Node* node, T key)
{
    if (!node) return nullptr;

    if (key < node->value)
    {
        node->left = erase(node->left, key);
    }
    else if (key > node->value)
    {
        node->right = erase(node->right, key);
    }
    else
    {
        if (!node->left)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node* successor = node->right;
            while (successor->left)
                successor = successor->left;

            node->value = successor->value;
            node->right = erase(node->right, successor->value);
        }
    }
    return node;
}

template<typename T>
Tree<T>::Tree(const Tree& other) : root(nullptr)
{
    if (other.root)
        insert(root, other.root->value);
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree& other)
{
    if (this == &other) return *this;

    clear(root);
    root = nullptr;

    if (other.root)
        insert(root, other.root->value);

    return *this;
}

template<typename T>
Tree<T>::~Tree()
{
    clear(root);
}

template<typename T>
void Tree<T>::insert(T value)
{
    insert(root, value);
}

template<typename T>
void Tree<T>::print() const
{
    print(root);
    cout << endl;
}

template<typename T>
void Tree<T>::erase(T key)
{
    root = erase(root, key);
}

template class Tree<int>;
template class Tree<string>;
