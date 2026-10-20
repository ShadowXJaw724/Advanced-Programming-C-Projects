#include <iostream>
#include <fstream>
#include "twosidelist.h"
using namespace std;

class SX {
public:
	int data;
	SX* prev;
	SX* next;
	SX(int o) : data(o), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
	SX* head; SX* tail; int size;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~DoubleLinkedList() { DLL_Clear(); }

	void DLL_InsertFront(int o) {
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

	int DLL_RemoveFront() {
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

	void DLL_InsertBack(int o) {
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

	int DLL_RemoveBack(){
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

	void DLL_InsertIDX(int o, int inx) {
		if (inx < 0 || inx > size) return;
		if (inx == 0) { DLL_InsertFront(o); return; }
		if (inx == size) { DLL_InsertBack(o); return; }
		SX* nSX = new SX(o); SX* current = head;
		for (int i = 0; i < inx; i++) {current = current->next;}
		nSX->prev = current->prev; nSX->next = current;
		current->prev->next = nSX; current->prev = nSX;
		size++;
	}

	int DLL_RemoveIDX(int inx) {
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

	int DLL_GetIDX(int inx) {
		if (inx < 0 || inx >= size) throw out_of_range("Indeks poza zakresem.");
		SX* current = head;
		for (int i = 0; i<inx; i++) current = current->next;
		return current->data;
	}

	int DLL_GetEnd(int inx) {
		if (inx < 0 || inx >= size) throw out_of_range("Indeks poza zakresem.");
		SX* current = tail;
		for (int i = 0; i < inx; i++) current = current->prev;
		return current->data;
	}

	void DLL_Clear() {
		SX* current = head;
		while (current != nullptr) {
			SX* t = current;
			current = current->next;
			delete t;
		}
		head = nullptr; tail = nullptr; size = 0;
	}

	void DLL_ForwardDisplay() {
		SX* current = head;
		while (current != nullptr) {
			cout << current->data << " [] ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	// Print list backward
	void DLL_BackwardDisplay() {
		SX* current = tail;
		while (current != nullptr) {
			cout << current->data << " [] ";
			current = current->prev;
		}
		cout << "NULL" << endl;
	}

};


int TSL() {
	DoubleLinkedList dll;
	dll.DLL_InsertFront(100);
	dll.DLL_InsertFront(200);
	dll.DLL_InsertBack(300);
	dll.DLL_InsertIDX(500, 1);

	dll.DLL_ForwardDisplay();
	dll.DLL_BackwardDisplay();

	dll.DLL_RemoveIDX(2);
	cout << dll.DLL_GetIDX(1) << endl;
	cout << dll.DLL_GetEnd(1) << endl;
    return 0;
}
