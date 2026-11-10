#ifndef SOURCE_CODE_BINARY_TREE_H
#define SOURCE_CODE_BINARY_TREE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief This is a class and struct to control and dictate how a Binary Search Tree would work.
 *
 * This firstly introduces the Node, with data and then left and right as would the
 * real binary tree. BTS is just a root with the left having smaller than and the right having
 * bigger than numerals. We can
 *
 */

struct Node {
     int data; Node* L; Node* R;
     Node(int o) : data(o), L(nullptr), R(nullptr) {}
     Node() : data(0), L(nullptr), R(nullptr) {}
};

class BST_System {
    int data; Node* L; Node* R;
    static bool FindPathRec(Node* node, int key, std::vector<int>& path);
public:
    BST_System(int o) : data(o), L(nullptr), R(nullptr) {}
    Node* CreateNode(int d) const;
    Node* InsertNode(Node *root, int d);
    Node* DeleteNode(Node *root, int d, bool found);

    Node *FindNode(Node *root, int key);
    static Node* minValueNode(Node* node);
    static void PreorderTraversalNode(Node *root, int depth);
    static void InorderTraversalNode(Node *root, int depth);
    static void PostorderTraversalNode(Node *root, int depth);
    static void EraseNode(Node* root);
};

#endif
