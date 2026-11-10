#ifndef SOURCE_CODE_FILE_MANAGER_H
#define SOURCE_CODE_FILE_MANAGER_H
#include "binary_tree.h"
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Klasa odpowiedzialna za zapis i odczyt danych z plików binarnych.
 *
 * Pozwala zapisać wartości z drzewa do pliku oraz
 * odczytać je i ponownie dodać do drzewa.
 */
class FileManager_System {

    /**
     * @brief Pomocnicza funkcja zapisująca wartości drzewa.
     *
     * Zapisuje dane rekurencyjnie w kolejności preorder.
     * @param root Aktualny węzeł drzewa.
     * @param file Strumień pliku, do którego zapisywane są dane.
     */
    static void SaveBinaryHelper(Node* root, std::ofstream& file);

public:

    /**
     * @brief Zapisuje zawartość drzewa do pliku binarnego.
     * @param root Korzeń drzewa.
     * @param filename Nazwa pliku do zapisu.
     */
    static void SaveToBinary(Node* root, const std::string& filename);

    /**
     * @brief Wczytuje wartości z pliku binarnego do drzewa.
     *
     * Każda odczytana wartość jest dodawana do drzewa
     * za pomocą funkcji InsertNode.
     * @param root Korzeń drzewa.
     * @param filename Nazwa pliku do odczytu.
     * @param bst Obiekt obsługujący operacje na drzewie.
     * @return Korzeń drzewa po wczytaniu danych.
     */
    static Node* LoadFromBinary(Node* root, const std::string& filename, BST_System& bst);
};
#endif
