#ifndef ADV_CODING_PROJECT_1_FACTORY_SYSTEM_H
#define ADV_CODING_PROJECT_1_FACTORY_SYSTEM_H

#include "twosidelist.h"

class factory_system {
public:
    static DoubleLinkedList createSampleList();
    static DoubleLinkedList createFromArray(const int* values, int count);
};

#endif
