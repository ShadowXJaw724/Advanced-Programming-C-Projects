#include <iostream>
#include "factory_system.h"
#include "iterator_system.h"
using namespace std;

int main() {
    DoubleLinkedList list = factory_system::createSampleList();

    cout << "forward (iterator): ";
    iterator_system::iterateforward(list);

    cout << "backward (iterator): ";
    iterator_system::iteratebackward(list);

    list.DLL_RemoveIDX(2);
    cout << "index 1: " << list.DLL_GetIDX(1) << endl;
    cout << "from end 1: " << list.DLL_GetEnd(1) << endl;
    list.DLL_Next();
    list.DLL_Prev();

    const int extra[] = {7, 8, 9};
    DoubleLinkedList fromArray = factory_system::createFromArray(extra, 3);
    cout << "from array: ";
    iterator_system::iterateforward(fromArray);

    return 0;
}
