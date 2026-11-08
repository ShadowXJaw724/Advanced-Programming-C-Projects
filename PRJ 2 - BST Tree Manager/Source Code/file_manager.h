#ifndef SOURCE_CODE_FILE_MANAGER_H
#define SOURCE_CODE_FILE_MANAGER_H
#include "binary_tree.h"
#include <fstream>
#include <iostream>
#include <string>

class FileManager_System {
    static void SaveBinaryHelper(Node* root, std::ofstream& file);

public:
    static void SaveToBinary(Node* root, const std::string& filename);
    static Node* LoadFromBinary(Node* root, const std::string& filename, BST_System& bst);
};

#endif
