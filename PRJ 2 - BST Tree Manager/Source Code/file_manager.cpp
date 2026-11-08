#include "file_manager.h"

void FileManager_System::SaveBinaryHelper(Node* root, std::ofstream& file) {
    if (root != nullptr) {
        file.write(reinterpret_cast<const char*>(&(root->data)), sizeof(int));
        SaveBinaryHelper(root->L, file);
        SaveBinaryHelper(root->R, file);
    }
}

void FileManager_System::SaveToBinary(Node* root, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        SaveBinaryHelper(root, file);
        file.close();
        std::cout << "Tree saved to binary file: " << filename << "\n";
    } else {
        std::cout << "Error opening binary file for writing.\n";
    }
}

Node* FileManager_System::LoadFromBinary(Node* root, const std::string& filename, BST_System& bst) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error opening binary file for reading.\n"; return root;
    }
    int val;
    while (file.read(reinterpret_cast<char*>(&val), sizeof(int))) root = bst.InsertNode(root, val);
    file.close();
    std::cout << "Data loaded from binary file.\n";
    return root;
}
