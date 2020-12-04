#include <string>
#include "SingleLinkedList.h"

// Driver used to test and use the SingleLinkedList
int main() {
	SingleLinkedList<string>* list = new SingleLinkedList<string>();
	string* items[4];
	int size = sizeof(items) / sizeof(string*);

	items[0] = new string("A");
	items[1] = new string("B");
	items[2] = new string("C");
	items[3] = new string("D");

	string* value1 = new string("E");
	string* value2 = new string("F");

	try {
		list->print();

		cout << "\nUsing add(T* element)" << endl;
		for (int i = 0; i < size; i++) {
			list->add(items[i]);
			cout << "add(" << *items[i] << ") -> ";
			list->print();
		}


		cout << "\nUsing remove(T* element)" << endl;
		for (int i = 0; i < size; i++) {
			string* item = list->remove(items[i]);
			cout << "remove(" << *items[i] << ") = " << *item << " -> ";
			list->print();
		}


		cout << "\nUsing addToFront(T* element)" << endl;
		for (int i = 0; i < size; i++) {
			list->addToFront(items[i]);
			cout << "addToFront(" << *items[i] << ") -> ";
			list->print();
		}


		cout << "\nUsing removeFirst()" << endl;
		for (int i = 0; i < size; i++) {
			string* item = list->removeFirst();
			cout << "removeFirst() = " << *item << " -> ";
			list->print();
		}


		cout << "\nUsing addToRear(T* element)" << endl;
		for (int i = 0; i < size; i++) {
			list->addToRear(items[i]);
			cout << "addToRear(" << *items[i] << ") -> ";
			list->print();
		}


		cout << "\nUsing removeLast()" << endl;
		for (int i = 0; i < size; i++) {
			string* item = list->removeLast();
			cout << "removeLast() = " << *item << " -> ";
			list->print();
		}


		cout << "\nUsing add(int index, T* element)" << endl;
		for (int i = 0; i < size; i++) {
			list->add(i, items[i]);
			cout << "add(" << i << ", " << *items[i] << ") -> ";
			list->print();
		}


		cout << "\nUsing remove(int index)" << endl;
		for (int i = 0; i < size; i++) {
			string* item = list->remove(0);
			cout << "remove(" << i << ") = " << *item << " -> ";
			list->print();
		}


		list->add(items[0]);
		cout << endl << "add(" << *items[0] << ") -> ";;
		list->print();

		cout << "\nUsing addAfter(T* element, T* target)" << endl;
		for (int i = 1; i < size; i++) {
			list->addAfter(items[i], items[0]);
			cout << "addAfter(" << *items[i] << ", " << *items[0] << ") -> ";
			list->print();
		}


		cout << "\nUsing set(int index, T* element)" << endl;
		list->set(0, value1);
		cout << "set(" << 0 << ", " << *value1 << ") -> ";
		list->print();


		cout << "\nUsing get(int index)" << endl;
		for (int i = 0; i < size; i++) {
			cout << "get(" << i << ") = " << *(list->get(i)) << endl;
		}


		cout << "\nUsing first()" << endl;
		cout << "first() = " << *(list->first()) << endl;


		cout << "\nUsing last()" << endl;
		cout << "last() = " << *(list->last()) << endl;


		cout << "\nUsing indexOf(T* element)" << endl;
		cout << "indexOf(" << *value1 << ") = " << list->indexOf(value1) << endl;
		for (int i = 1; i < size; i++) {
			cout << "indexOf(" << *items[i] << ") = " << list->indexOf(items[i]) << endl;
		}
		cout << "indexOf(" << *value2 << ") = " << list->indexOf(value2) << endl;


		cout << "\nUsing contains(T* element)" << endl;
		cout << "contains(" << *value1 << ") = " << (list->contains(value1) ? "TRUE" : "FALSE") << endl;
		for (int i = 1; i < size; i++) {
			cout << "contains(" << *items[i] << ") = " << (list->contains(items[i]) ? "TRUE" : "FALSE") << endl;
		}
		cout << "contains(" << *value2 << ") = " << (list->contains(value2) ? "TRUE" : "FALSE") << endl;


		cout << "\nUsing isEmpty()" << endl;
		cout << "isEmpty() = " << (list->isEmpty() ? "TRUE" : "FALSE") << endl;


		cout << "\nUsing getSize()" << endl;
		cout << "getSize() = " << list->getSize() << endl;

	} catch (const char* msg) {
		cerr << msg << endl;
	}

	// Delete items to prevent memeory leaking
	delete list;
	delete value2;

	return 0;
}
