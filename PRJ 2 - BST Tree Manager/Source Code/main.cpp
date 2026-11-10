#include <iostream>
#include "binary_tree.h"
#include "file_manager.h"

/**
 * @author Kacper Twaróg
 * @date 2026-11-12
 */

/**
 * @file binary_tree.h
 * @brief Plik nagłówkowy algorytmu drzewa wyszukiwania binarnego, który został zaimplementowany w C++.
 */

/**
 * @file file_manager.h
 * @brief Plik nagłówkowy klasy menedżera plików umożliwiający prosty zapis/odczyt plików binarnych.
 */

int main() {
    int a; std::cout << "Wybierz liczbe jako srodek drzewa binarnego: ";
    std::cin >> a;
    BST_System BST = a;
    FileManager_System FM;
    Node* root = BST.CreateNode(a);
    string filen;
    bool found = false;
    int choice = -1;

    /**
     * @brief Definiowanie różnych zmiennych do obsługi systemu.
     * @param a Tymczasowa zmienna rozpoczynająca drzewo binarne, ponieważ regularnie zaczynała się od 0, przerwała
     * sekwencjonowanie, ponieważ korzeń stał się 0, dlatego wszystkie liczby byłyby po jednej stronie.
     * @param BST Instancja klasy Binary Search Tree.
     * @param FM Instancja klasy Menedżer plików odpowiedzialna za konwersję i odszyfrowanie z czystego pliku binarnego.
     * @param root Korzeń naszego drzewa binarnego i na czym opiera się cały ten program.
     * @param filen Reprezentuje nazwę pliku, na której będziemy polegać podczas pracy z operacjami wejścia i wyjścia systemu.
     * @param found Wartość logiczna sprawdzająca, czy funkcja DeleteNode znajduje węzeł do usunięcia.
     * @param choice Prosty int pozwala nam używać przypadków przełączników do przechodzenia przez nieskończoną liczbę wyborów
     * symulujących menu w celu przetestowania modułu drzewa wyszukiwania binarnego.
     */

    while (choice != 0) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "67. Dodaj przykladowe drzewo\n";
        std::cout << "1. Dodaj Element\n";
        std::cout << "2. Usun Element\n";
        std::cout << "3. Usun Cale Drzewo\n";
        std::cout << "4. Pokaz Drzewo (Pre-Order)\n";
        std::cout << "5. Pokaz Drzewo (In-Order)\n";
        std::cout << "6. Pokaz Drzewo (Post-Order)\n";
        std::cout << "7. Znajdz droge do Elementu\n";
        std::cout << "8. Zapisz do pliku\n";
        std::cout << "9. Wczytaj z pliku (overwrite)\n";
        std::cout << "11. Wczytaj z pliku (append)\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
            case 67:
                BST.InsertNode(root, 50);
                BST.InsertNode(root, 60);
                BST.InsertNode(root, 25);
                BST.InsertNode(root, 3);
                BST.InsertNode(root, 150);
                BST.InsertNode(root, 70);
                break;
            case 1: {
                int v; std::cout << "Dodaj walute do drzewa: ";
                std::cin >> v; root = BST.InsertNode(root, v);
                break;
            }
            case 2: {
                int v; std::cout << "Usuń walute z drzewa: ";
                std::cin >> v; root = BST.DeleteNode(root, v, found);
                if (!found) std::cout << "Waluty nie było w drzewie!: ";
                break;
            }
            case 3:
                BST.EraseNode(root);
                std::cout << "Drzewo usunięte.\n";
                break;
            case 4:
                BST.PreorderTraversalNode(root, 0); break;
            case 5:
                BST.InorderTraversalNode(root, 0); break;
            case 6:
                BST.PostorderTraversalNode(root, 0); break;
            case 7:
                int v; std::cout << "Wybierz walute do wyszukania: ";
                std::cin >> v; root = BST.FindNode(root, v); break;
            case 8:
                std::cout << "Podaj imie pliku do ktorego zapisac: ";
                std::cin >> filen; FM.SaveToBinary(root, filen); break;
            case 9: {
                std::cout << "Podaj imie pliku do wczytania (overwrite): ";
                root = nullptr;
                std::cin >> filen; root = FM.LoadFromBinary(root, filen, BST);
                break; }
            case 11: {
                std::cout << "Podaj imie pliku do wczytania (append): ";
                std::cin >> filen; root = FM.LoadFromBinary(root, filen, BST);
                break;
            }
            case 0:
                BST.EraseNode(root);
                std::cout << "Wychodzenie z programu...";
            default:
                break;
        }
    }

    /**
     * @brief System do testowania drzewa wyszukiwania binarnego i jego działania.
    * @details System switch case umożliwiający testowanie dodawania węzłów, usuwania węzłów, usuwania całego drzewa,
     * metod znajdowania węzła, kolejności wstępnej i końcowej, zapisywania i ładowania do pliku oraz szybkiego podawania
     * wstępnie ustawionej listy do przetestowania.
     */
    return 0;
}