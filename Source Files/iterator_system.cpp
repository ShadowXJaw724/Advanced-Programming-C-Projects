#include "iterator_system.h"
#include "twosidelist.h"
#include <iostream>
#include <stdexcept>
using namespace std;

iterator_system::iterator_system(SX* start) : current(start) {}

bool iterator_system::hasNext() const { return current != nullptr; }
bool iterator_system::hasPrev() const { return current != nullptr; }

void iterator_system::iterateforward(DoubleLinkedList &list) {
    for (auto it = iterator_system::begin(list); it.hasNext(); )
        cout << it.next() << " ";
    cout << endl;
}

void iterator_system::iteratebackward(DoubleLinkedList &list) {
    for (auto it = iterator_system::rbegin(list); it.hasPrev(); )cout << it.prev() << " ";
    cout << endl;
}

int iterator_system::next() {
    if (current == nullptr)
        throw std::out_of_range("iterator has no next element");
    int value = current->data;
    current = current->next;
    return value;
}

int iterator_system::prev() {
    if (current == nullptr)
        throw std::out_of_range("iterator has no previous element");
    int value = current->data;
    current = current->prev;
    return value;
}

iterator_system iterator_system::begin(DoubleLinkedList& list) {
    return iterator_system(list.head);
}

iterator_system iterator_system::rbegin(DoubleLinkedList& list) {
    return iterator_system(list.tail);
}
