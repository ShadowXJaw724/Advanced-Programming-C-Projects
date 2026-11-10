/**
 * @brief Struktura przechowująca pojedynczy węzeł drzewa.
 *
 * Każdy węzeł przechowuje wartość oraz wskaźniki
 * na lewe i prawe dziecko.
 */
struct Node {
    int data;
    Node* L;
    Node* R;

    /**
     * @brief Tworzy pusty węzeł z podaną wartością.
     * @param o Wartość przechowywana w węźle.
     */
    Node(int o) : data(o), L(nullptr), R(nullptr) {}

    /**
     * @brief Tworzy węzeł z wartością początkową równą 0.
     */
    Node() : data(0), L(nullptr), R(nullptr) {}
};

/**
 * @brief Klasa obsługująca operacje na drzewie wyszukiwania binarnego.
 *
 * Umożliwia tworzenie, dodawanie, usuwanie i wyszukiwanie
 * elementów drzewa oraz wyświetlanie jego zawartości.
 */
class BST_System {
    int data;
    Node* L;
    Node* R;

    /**
     * @brief Rekurencyjnie szuka wartości i zapisuje przebytą drogę.
     * @param node Aktualny węzeł.
     * @param key Szukana wartość.
     * @param path Wektor przechowujący kolejne wartości na drodze.
     * @return true, jeśli znaleziono wartość, w przeciwnym razie false.
     */
    static bool FindPathRec(Node* node, int key, std::vector<int>& path);

public:

    /**
     * @brief Konstruktor klasy BST_System.
     * @param o Początkowa wartość klasy.
     */
    BST_System(int o) : data(o), L(nullptr), R(nullptr) {}

    /**
     * @brief Tworzy nowy węzeł drzewa.
     * @param d Wartość nowego węzła.
     * @return Wskaźnik na utworzony węzeł.
     */
    Node* CreateNode(int d) const;

    /**
     * @brief Dodaje nową wartość do drzewa.
     * @param root Korzeń drzewa.
     * @param d Wartość do dodania.
     * @return Wskaźnik na korzeń drzewa po dodaniu elementu.
     */
    Node* InsertNode(Node* root, int d);

    /**
     * @brief Usuwa wybraną wartość z drzewa.
     * @param root Korzeń drzewa.
     * @param d Wartość do usunięcia.
     * @param found Zmienna informująca o znalezieniu elementu.
     * @return Wskaźnik na korzeń drzewa po usunięciu.
     */
    Node* DeleteNode(Node* root, int d, bool& found);

    /**
     * @brief Wyszukuje wartość i wyświetla drogę do niej.
     * @param root Korzeń drzewa.
     * @param key Szukana wartość.
     * @return W obecnej implementacji funkcja nie zwraca poprawnie wskaźnika.
     */
    Node* FindNode(Node* root, int key);

    /**
     * @brief Znajduje najmniejszą wartość w poddrzewie.
     * @param node Korzeń sprawdzanego poddrzewa.
     * @return Wskaźnik na węzeł z najmniejszą wartością.
     */
    static Node* minValueNode(Node* node);

    /**
     * @brief Wyświetla drzewo w kolejności preorder.
     * @param root Korzeń drzewa.
     * @param depth Aktualna głębokość węzła.
     */
    static void PreorderTraversalNode(Node* root, int depth);

    /**
     * @brief Wyświetla drzewo w odwróconej kolejności inorder.
     * @param root Korzeń drzewa.
     * @param depth Aktualna głębokość węzła.
     */
    static void InorderTraversalNode(Node* root, int depth);

    /**
     * @brief Wyświetla drzewo w kolejności postorder.
     * @param root Korzeń drzewa.
     * @param depth Aktualna głębokość węzła.
     */
    static void PostorderTraversalNode(Node* root, int depth);

    /**
     * @brief Usuwa rekurencyjnie wszystkie węzły drzewa.
     * @param root Korzeń drzewa do usunięcia.
     */
    static void EraseNode(Node* root);
};