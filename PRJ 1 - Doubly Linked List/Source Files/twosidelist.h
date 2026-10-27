#pragma once
#include <iostream>

class SX { /*!< Detailed description after the member */
public:
	int data;
	SX* prev;
	SX* next;
	SX(int o) : data(o), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
	SX* head;
	SX* tail;
	int size;

public:
	friend class iterator_system;
	DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	DoubleLinkedList(const DoubleLinkedList&) = delete;
	DoubleLinkedList& operator=(const DoubleLinkedList&) = delete;
	DoubleLinkedList(DoubleLinkedList&& other) noexcept
		: head(other.head), tail(other.tail), size(other.size) {}
	DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept {
		if (this != &other) {
			DLL_Clear();
			head = other.head;
			tail = other.tail;
			size = other.size;
			other.head = nullptr;
			other.tail = nullptr;
			other.size = 0;
		}
		return *this;
	}
	~DoubleLinkedList() { DLL_Clear(); }

	void DLL_InsertFront(int o);
	int DLL_RemoveFront();
	void DLL_InsertBack(int o);
	int DLL_RemoveBack();
	void DLL_InsertIDX(int o, int inx);
	int DLL_RemoveIDX(int inx);
	int DLL_GetIDX(int inx);
	int DLL_GetEnd(int inx);
	void DLL_Clear();
	void DLL_ForwardDisplay();
	void DLL_BackwardDisplay();
	void DLL_Next();
	void DLL_Prev();
};

