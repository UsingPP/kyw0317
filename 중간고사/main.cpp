#include "DoubleLinkedList.hpp"

int main() {
	DoubleLinkedList d;
	int item;
	d.InsertItem(1);
	d.InsertItem(2);
	d.InsertItem(3);
	d.InsertItem(4);
	d.InsertItem(5);


	DoubleLinkedList e = d;
	DoubleLinkedList f;
	f = d;
	ListIterator iter(d);

	iter.GetNextItem(item);
	iter.GetNextItem(item);
	iter.GetPrivItem(item);
	return 0;
}