#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "binary_tree.h"

void Core() {
    BST_System bst = 0;
    Node* root = nullptr;

    std::cout << "Testing inserting\n";
    std::vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = bst.InsertNode(root, v);

    std::cout << "\nTesting moving\n";
    std::cout << "Inorder (Reverse for graphical layout):\n";
    bst.InorderTraverseNode(root, 0);

    std::cout << "\nPreorder:\n";
    bst.PreorderTraversalNode(root, 0);

    std::cout << "\nPostorder:\n";
    bst.PostorderTraverseNode(root, 0);

    std::cout << "\nTesting path finding\n";
    int searchKey = 40;
    Node* found = bst.FindNode(root, searchKey);
    if (found) std::cout << "Node " << searchKey << " found in tree.\n";
    else std::cout << "Node " << searchKey << " NOT found.\n";


    bst.FindNode(root, searchKey);
    bst.FindNode(root, 99);

    std::cout << "\nTesting deleting\n";
    std::cout << "Deleting leaf node (20)\n";
    root = bst.DeleteNode(root, 20);

    std::cout << "Deleting node with one child (85 with 80))\n";
    root = bst.InsertNode(root, 85);
    root = bst.DeleteNode(root, 80);

    std::cout << "Deleting node with two children (50)\n";
    root = bst.DeleteNode(root, 50);

    std::cout << "\nTree after deletions (Inorder layout):\n";
    bst.InorderTraverseNode(root, 0);
}

int main() { Core(); return 0; }