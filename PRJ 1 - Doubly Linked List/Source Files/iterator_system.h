#ifndef ADV_CODING_PROJECT_1_ITERATOR_SYSTEM_H
#define ADV_CODING_PROJECT_1_ITERATOR_SYSTEM_H

class DoubleLinkedList;
class SX;

class iterator_system {
    SX* current;
    explicit iterator_system(SX* start);

public:
    bool hasNext() const;
    int next();
    bool hasPrev() const;
    int prev();

    static void iterateforward(DoubleLinkedList &list);
    static void iteratebackward(DoubleLinkedList &list);

    static iterator_system begin(DoubleLinkedList& list);
    static iterator_system rbegin(DoubleLinkedList& list);
};

#endif
