#include <iostream>
#include <vector>
#include "mergeSort.h"
using namespace std;

int main() {
    vector<int> IntTest = {2, 4, 6, 9, 11, 3, 1, 44, 129, 8};
    vector<double> DoubleTest = {2.23, 4.22, 6.33, 9.44, 11.23, 3.91, 1.123, 44.129, 129.98765, 8.532};

    cout << "Before: "; MergeSortAlg<int>::PrintVector(IntTest); cout << endl;
    cout << "Before: "; MergeSortAlg<double>::PrintVector(DoubleTest); cout << endl;

    MergeSortAlg<int>::MergeSort(IntTest, 0, static_cast<int>(IntTest.size()) - 1);
    MergeSortAlg<double>::MergeSort(DoubleTest, 0, static_cast<int>(DoubleTest.size()) - 1);

    cout << "After: "; MergeSortAlg<int>::PrintVector(IntTest); cout << endl;
    cout << "After: "; MergeSortAlg<double>::PrintVector(DoubleTest); cout << endl;

    return 0;
}
