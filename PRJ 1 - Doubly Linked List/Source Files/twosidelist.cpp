#include <iostream>
#include <stdexcept>
#include "twosidelist.h"
using namespace std;

void DoubleLinkedList::DLL_InsertFront(int o) {
	SX* nSX = new SX(o);
	if (head == nullptr) {
		head = nSX;
		tail = nSX;
	} else {
		nSX->next = head;
		head->prev = nSX;
		head = nSX;
	}
	size++;
}

int DoubleLinkedList::DLL_RemoveFront() {
	if (head == nullptr) throw out_of_range("DLL jest pusty.");
	int d = head->data; SX* t = head;
	if (size == 1) {
		head = nullptr;
		tail = nullptr;
	} else {
		head = head->next;
		head->prev = nullptr;
	}
	delete t; size--; return d;
}

void DoubleLinkedList::DLL_InsertBack(int o) {
	SX* nSX = new SX(o);
	if (head == nullptr) {
		head = nSX;
		tail = nSX;
	} else {
		nSX->prev = tail;
		tail->next= nSX;
		tail = nSX;
	}
	size++;
}

int DoubleLinkedList::DLL_RemoveBack(){
	if (tail == nullptr) throw out_of_range("DLL jest pusty.");
	int d = tail->data; SX* t = tail;
	if (size == 1) {
		head = nullptr;
		tail = nullptr;
	} else {
		tail = tail->next;
		tail->prev = nullptr;
	}
	delete t; size--; return d;
}

void DoubleLinkedList::DLL_InsertIDX(int o, int inx) {
	if (inx < 0 || inx > size) return;
	if (inx == 0) { DLL_InsertFront(o); return; }
	if (inx == size) { DLL_InsertBack(o); return; }
	SX* nSX = new SX(o); SX* current = head;
	for (int i = 0; i < inx; i++) {current = current->next;}
	nSX->prev = current->prev; nSX->next = current;
	current->prev->next = nSX; current->prev = nSX;
	size++;
}

int DoubleLinkedList::DLL_RemoveIDX(int inx) {
	if (inx < 0 || inx >= size) throw out_of_range("Indeks poza zakresem.");
	if (inx == 0) return DLL_RemoveFront(); if (inx == size - 1) return DLL_RemoveBack();
	SX* current = head;
	for (int i = 0; i<inx; i++) current = current->next;
	int d = current->data;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	size--;
	return d;
}

int DoubleLinkedList::DLL_GetIDX(int inx) {
	if (inx < 0 || inx >= size) throw out_of_range("Indeks poza zakresem.");
	SX* current = head;
	for (int i = 0; i<inx; i++) current = current->next;
	return current->data;
}

int DoubleLinkedList::DLL_GetEnd(int inx) {
	if (inx < 0 || inx >= size) throw out_of_range("Indeks poza zakresem.");
	SX* current = tail;
	for (int i = 0; i < inx; i++) current = current->prev;
	return current->data;
}

void DoubleLinkedList::DLL_Clear() {
	SX* current = head;
	while (current != nullptr) {
		SX* t = current;
		current = current->next;
		delete t;
	}
	head = nullptr; tail = nullptr; size = 0;
}

void DoubleLinkedList::DLL_ForwardDisplay() {
	SX* current = head;
	while (current != nullptr) {
		cout << current->data << " [] ";
		current = current->next;
	}
	cout << "NULL" << endl;
}

void DoubleLinkedList::DLL_BackwardDisplay() {
	SX* current = tail;
	while (current != nullptr) {
		cout << current->data << " [] ";
		current = current->prev;
	}
	cout << "NULL" << endl;
}

void DoubleLinkedList::DLL_Next() {
	SX* current = head;
	if (current == nullptr) cout << "Nie ma nic po.";
	else cout << current->data << endl;
}
void DoubleLinkedList::DLL_Prev() {
	SX* current = tail;
	if (current == nullptr) cout << "Nie ma nic przed.";
	else cout << current->data << endl;
}