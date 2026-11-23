#include "mergeSort.h"

#include <gtest/gtest.h>
#include <vector>

/**
 * @brief Sprawdza, czy posortowany wektor pozostaje bez zmian.
 */
TEST(MergeSortTest, PreservesSortedVector) {
    std::vector<int> values = {1, 2, 3, 4, 5};
    const std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie wektora ułożonego w odwrotnej kolejności.
 */
TEST(MergeSortTest, SortsReverseOrderedVector) {
    std::vector<int> values = {5, 4, 3, 2, 1};
    const std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie wektora z losowo ułożonymi liczbami.
 */
TEST(MergeSortTest, SortsRandomVector) {
    std::vector<int> values = {8, 3, 12, 1, 9, 4, 6};
    const std::vector<int> expected = {1, 3, 4, 6, 8, 9, 12};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie wektora zawierającego tylko liczby ujemne.
 */
TEST(MergeSortTest, SortsOnlyNegativeNumbers) {
    std::vector<int> values = {-3, -8, -1, -12, -5};
    const std::vector<int> expected = {-12, -8, -5, -3, -1};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie liczb dodatnich i ujemnych.
 */
TEST(MergeSortTest, SortsPositiveAndNegativeNumbers) {
    std::vector<int> values = {4, -2, 7, -8, 0, 3};
    const std::vector<int> expected = {-8, -2, 0, 3, 4, 7};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza obsługę pustego wektora bez rzucania wyjątku.
 */
TEST(MergeSortTest, HandlesEmptyVector) {
    std::vector<int> values;
    EXPECT_NO_THROW(MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1));
    EXPECT_TRUE(values.empty());
}

/**
 * @brief Sprawdza, czy wektor z jednym elementem pozostaje bez zmian.
 */
TEST(MergeSortTest, HandlesSingleElement) {
    std::vector<int> values = {42};
    const std::vector<int> expected = {42};
    MergeSortAlg<int>::MergeSort(values,0,0);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie wektora zawierającego duplikaty.
 */
TEST(MergeSortTest, SortsDuplicates) {
    std::vector<int> values = {4, 2, 4, 1, 2, 4};
    const std::vector<int> expected = {1, 2, 2, 4, 4, 4};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie ujemnych liczb zawierających duplikaty.
 */
TEST(MergeSortTest, SortsNegativeDuplicates) {
    std::vector<int> values = {-4, -2, -4, -1, -2, -4};
    const std::vector<int> expected = {-4, -4, -4, -2, -2, -1};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie liczb dodatnich, ujemnych oraz duplikatów.
 */
TEST(MergeSortTest, SortsIntegersWithNegativesAndDuplicates) {
    std::vector<int> values = {4, -2, 7, 4, 0, -5};
    const std::vector<int> expected = {-5, -2, 0, 4, 4, 7};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza, czy dwa poprawnie ułożone elementy pozostają bez zmian.
 */
TEST(MergeSortTest, PreservesTwoSortedElements) {
    std::vector<int> values = {1, 2};
    const std::vector<int> expected = {1, 2};
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie dużego wektora zawierającego ponad 100 elementów.
 */
TEST(MergeSortTest, SortsLargeVector) {
    std::vector<int> values;
    std::vector<int> expected;
    for (int i = 150; i >= 0; i--) values.push_back(i);
    for (int i = 0; i <= 150; i++) expected.push_back(i);
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza duży wektor z liczbami ujemnymi, dodatnimi i duplikatami.
 */
TEST(MergeSortTest, SortsLargeVectorWithNegativesPositivesAndDuplicates) {
    std::vector<int> values;
    std::vector<int> expected;
    for (int i = 0; i < 50; i++) {
        values.push_back(5);
        values.push_back(-3);
        values.push_back(10);
    }
    for (int i = 0; i < 50; i++) expected.push_back(-3);
    for (int i = 0; i < 50; i++) expected.push_back(5);
    for (int i = 0; i < 50; i++) expected.push_back(10);
    MergeSortAlg<int>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza działanie algorytmu dla typu double.
 */
TEST(MergeSortTest, SortsDoubles) {
    std::vector<double> values = {2.23, -1.5, 0.0, 1.123, 2.23};
    const std::vector<double> expected = {-1.5, 0.0, 1.123, 2.23, 2.23};
    MergeSortAlg<double>::MergeSort(values,0,static_cast<int>(values.size()) - 1);
    EXPECT_EQ(values, expected);
}

/**
 * @brief Sprawdza sortowanie tylko wybranego zakresu wektora.
 */
TEST(MergeSortTest, SortsOnlyRequestedRange) {
    std::vector<int> values = {99, 4, 1, 3, 2, -99};
    const std::vector<int> expected = {99, 1, 2, 3, 4, -99};
    MergeSortAlg<int>::MergeSort(values,1,4);
    EXPECT_EQ(values, expected);
}