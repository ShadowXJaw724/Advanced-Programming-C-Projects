#include <iostream>
#include "factory_system.h"
#include "iterator_system.h"
#include "twosidelist.h"
using namespace std;

int main() {

    /**
    * Program's main function. Here we use our factory method to create a sample list to test the project.
    * With this, we test forward and backward iteration, removing from index, getting from various points,
    * as well as getting next and previous. Then we do some operations on an array.
    */

    DoubleLinkedList list = factory_system::createSampleList();

    cout << "Display entire list: ";
    list.DLL_ForwardDisplay();

    cout << "Testing forward iteration on the sample list: ";
    iterator_system::iterateforward(list);

    cout << "Testing backward iteration on the sample list: ";
    iterator_system::iteratebackward(list);

    cout << "Testing removing Index on the sample list: ";
    list.DLL_RemoveIDX(2);

    cout << "Display entire list [Post-Remove]: ";
    list.DLL_ForwardDisplay();

    cout << "Display Index 1 Slot: " << list.DLL_GetIDX(1) << endl;
    cout << "From opposite Index 1 Slot: " << list.DLL_GetEnd(1) << endl;

    cout << "Next Node's Value: ";
    list.DLL_Next();
    cout << endl;

    cout << "Previous Node's Value: ";
    list.DLL_Prev();
    cout << endl;

    const int extra[] = {7, 8, 9};
    DoubleLinkedList fromArray = factory_system::createFromArray(extra, 3);
    cout << "Testing system from an array: ";
    iterator_system::iterateforward(fromArray);

    return 0;
}
