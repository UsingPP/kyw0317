#pragma once
#include <iostream>

class NodeType;
class DoubleLinkedList;

class NodeType {
	friend class ListIterator;
	friend class DoubleLinkedList;
private :
	int info;
	NodeType* next = nullptr;
	NodeType* back = nullptr;
};

class DoubleLinkedList {
	friend class ListIterator;
public:

	DoubleLinkedList();
	~DoubleLinkedList();
	void MakeEmpty();
	void InsertItem(int item);
	DoubleLinkedList(const DoubleLinkedList& org);
	DoubleLinkedList& operator=(const DoubleLinkedList& org);

	NodeType* currentPos;
	NodeType* datalist;
};


DoubleLinkedList::DoubleLinkedList() {
	currentPos = nullptr;
	if (datalist == nullptr) {
		NodeType* tempItem;
		tempItem = new NodeType;
		tempItem->info = INT_MIN;
		datalist = tempItem;

		tempItem = new NodeType;
		tempItem->info = INT_MAX;
		tempItem->next = datalist;
		datalist = tempItem;
		currentPos = datalist;

		(datalist->next)->back = datalist;
	}
}

DoubleLinkedList::~DoubleLinkedList() {
	NodeType* tempPtr;
	while (datalist != nullptr)
	{
		tempPtr = datalist;
		datalist = datalist->next;
		delete tempPtr;
	}
}

void DoubleLinkedList::MakeEmpty()
{
	NodeType* tempPtr;
	while (datalist != NULL)
	{
		tempPtr = datalist;
		datalist = datalist->next;
		delete tempPtr;
	}

	NodeType* tempItem;
	tempItem = new NodeType;
	tempItem->info = INT_MIN;
	datalist = tempItem;

	tempItem = new NodeType;
	tempItem->info = INT_MAX;
	tempItem->next = datalist;
	datalist = tempItem;

	(datalist->next)->back = datalist;
}

void DoubleLinkedList::InsertItem(int item) {
	NodeType* tempItem;
	NodeType* location = datalist->next;
	NodeType* predLoc = datalist;

	tempItem = new NodeType;
	tempItem->info = item;
	tempItem->next = location;

	location->back = tempItem;
	predLoc->next = tempItem;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& org) {
	NodeType* copy = org.datalist;
	NodeType* tempItem;
	if (datalist == nullptr) {
		tempItem = new NodeType;
		tempItem->info = INT_MIN;
		datalist = tempItem;

		tempItem = new NodeType;
		tempItem->info = INT_MAX;
		tempItem->next = datalist;
		datalist = tempItem;
		currentPos = datalist;
		(datalist->next)->back = datalist;
	}


	while(copy->next != nullptr) {
		NodeType* location = datalist->next;
		NodeType* predLoc = datalist;
		tempItem = new NodeType;
		tempItem->info = copy->info;
		tempItem->next = location;

		location->back = tempItem;
		predLoc->next = tempItem;

		copy = copy->next;
	}
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& org) {
	NodeType* copy = org.datalist;
	NodeType* tempItem;
	if (datalist == nullptr) {
		tempItem = new NodeType;
		tempItem->info = INT_MIN;
		datalist = tempItem;

		tempItem = new NodeType;
		tempItem->info = INT_MAX;
		tempItem->next = datalist;
		datalist = tempItem;
		currentPos = datalist;
		(datalist->next)->back = datalist;
	}


	while (copy->next != nullptr) {
		NodeType* location = datalist->next;
		NodeType* predLoc = datalist;
		tempItem = new NodeType;
		tempItem->info = copy->info;
		tempItem->next = location;

		location->back = tempItem;
		predLoc->next = tempItem;

		copy = copy->next;
	}
	return *this;
}


class ListIterator {
public:
	ListIterator(const DoubleLinkedList& l) {
		list = l;
		current = l.currentPos;
	};
	bool NotNull() {
		if (current) return true;
		else return false;
	} // current가 Null이 아닌지를 확인
	bool NextNotNull() {
		if (current && current->next) return true;
		else return false;
	}
	bool PrivNotNull() {
		if (current && current->back) return true;
		else return false;
	}
	void ResetList() {
		current = list.datalist;
	} // current를 첫 노드 포인터로 set
	int GetNextItem(int& item) {
		if (NextNotNull()) {
			item = (current->next)->info;
			current = current->next;
			return 1;
		}
		else return 0;
	}
	int GetPrivItem(int& item) {
		if (PrivNotNull()) {
			item = (current->back)->info;
			current = current->back;
			return 1;
		}
		else return 0;
	}
private:
	DoubleLinkedList list; //기존의 리스트를 참조한다.
	NodeType* current; // list의 한 노드를 가리킨다.};
};

