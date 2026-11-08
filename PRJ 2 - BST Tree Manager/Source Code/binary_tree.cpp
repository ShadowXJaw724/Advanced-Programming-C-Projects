#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "binary_tree.h"

Node* BST_System::CreateNode(int d) const {
     Node* NewNode = new Node();
     NewNode->data = d; NewNode->L = NewNode->R = nullptr;
     return NewNode;
     cout << "New Node created:" << d << "\n";
}

Node* BST_System::InsertNode(Node *root, int data){
    if (root == nullptr) return CreateNode(data);
    if (data < root->data) root->L = InsertNode(root->L, data);
    else if (data > root->data) root->R = InsertNode(root->R, data);
    return root;
}

Node* BST_System::DeleteNode(Node* root,int d) {
    if (root == nullptr) return root;

    // If the data to be deleted is smaller than the root's data, then it lies in the left subtree
    if (d < root->data) root->L = DeleteNode(root->L, d);

    // If the data to be deleted is greater than the root's data, then it lies in the right subtree
    else if (d > root->data) root->R = DeleteNode(root->R, d);

    // if data is same as root's data, then this is the node to be deleted
    else {
        // node with only one child or no child
        if (root->L == nullptr) {
            Node* temp = root->R;
            delete root;
            return temp;
        }
        if (root->R == nullptr) {
            Node* temp = root->L;
            delete root;
            return temp;
        }
        // node with two children : Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->R);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->R = DeleteNode(root->R, temp->data);
    }
    return root;
}

void BST_System::PreorderTraversalNode(Node* root, int depth) {
    if (root != nullptr) {
        for (int i = 0; i < depth; i++) std::cout << (i == depth - 1 ? "|-- " : "    ");
        std::cout << root->data << "\n";
        PreorderTraversalNode(root->L, depth + 1);
        PreorderTraversalNode(root->R, depth + 1);
    }
}

void BST_System::InorderTraversalNode(Node* root, int depth) {
    if (root != nullptr) {
        InorderTraversalNode(root->R, depth + 1);
        for (int i = 0; i < depth; i++) std::cout << "    ";
        std::cout << "--- " << root->data << "\n";
        InorderTraversalNode(root->L, depth + 1);
    }
}

void BST_System::PostorderTraversalNode(Node* root, int depth) {
    if (root != nullptr) {
        PostorderTraversalNode(root->L, depth + 1);
        PostorderTraversalNode(root->R, depth + 1);
        for (int i = 0; i < depth; i++) std::cout << "    ";
        std::cout << "-> " << root->data << "\n";
    }
}

bool BST_System::FindPathRec(Node* node, int key, std::vector<int>& path) {
    if (node == nullptr) return false;

    path.push_back(node->data);

    if (node->data == key) return true;
    if (key < node->data) return FindPathRec(node->L, key, path);

    return FindPathRec(node->R, key, path);
}

Node *BST_System::FindNode(Node *root, int key) {
    std::vector<int> path;

    if (FindPathRec(root, key, path)) {
        std::cout << "Droga do waluty " << key << ": ";
        for (size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i != path.size() - 1) std::cout << " -> ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Waluta " << key << " nie byla znaleziona.\n";
    }
}

Node* BST_System::minValueNode(Node* node){
    Node* current = node;
    while (current && current->L != nullptr) current = current->L;
    return current;
}

void BST_System::EraseNode(Node* node) {
    if (node != nullptr) {
        EraseNode(node->L);
        EraseNode(node->R);
        delete node;
    }
}
