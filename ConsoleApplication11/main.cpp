#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int> tree;

    tree.insert(5);
    tree.insert(2);
    tree.insert(4);
    tree.insert(70);

    cout << "Tree elements: ";
    tree.print();

    tree.erase(4);
    cout << "After erasing 4: ";
    tree.print();

    Tree<int> copyTree = tree;
    cout << "Copied tree: ";
    copyTree.print();

    Tree<int> assignedTree;
    assignedTree = tree;
    cout << "Assigned tree: ";
    assignedTree.print();
}
