#include "factory_system.h"
#include <iostream>

DoubleLinkedList factory_system::createSampleList() {
    DoubleLinkedList list;
    list.DLL_InsertFront(100);
    list.DLL_InsertFront(200);
    list.DLL_InsertBack(300);
    list.DLL_InsertIDX(500, 1);
    return list;
}

DoubleLinkedList factory_system::createFromArray(const int* values, int count) {
    DoubleLinkedList list;
    if (values == nullptr)
        return list;
    for (int i = 0; i < count; ++i)
        list.DLL_InsertBack(values[i]);
    return list;
}
