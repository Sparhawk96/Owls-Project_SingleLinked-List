#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T* data;
	Node<T>* next;
};

template <class T>
class SingleLinkedList
{
private:
	int size;
	Node<int>* head;
	Node<int>* tail;
public:
	//Constructor
	SingleLinkedList();
	
	//Adding
	void addToFront(T* element);
	void addToRear(T* element);
	void add(T* element);
	void add(int index, T* element);
	void addAfter(T* element, T* target);
	
	//Removing
	T* removeFirst();
	T* removeLast();
	T* remove(T* element);
	T* remove(int index);

	//Set
	void set(int index, T* element);

	//Get
	T* get(int index);
	T* first();
	T* last();

	//Misc
	int indexOf(T* element);
	bool contains(T* element);
	bool isEmpty();
	int getSize();

	//Delete
	~SingleLinkedList();
};

/* Construtor */

template <class T>
SingleLinkedList<T>::SingleLinkedList() {
	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
	cout << "Created a List" << endl;
};

/* Adding methods */

template <class T>
void SingleLinkedList<T>::addToFront(T* element) {
	cout << "Added Element (" << *element << ") to the front." << endl;
}

template <class T>
void SingleLinkedList<T>::addToRear(T* element) {
	cout << "Added Element (" << *element << ") to the rear." << endl;
}

template <class T>
void SingleLinkedList<T>::add(T* element) {
	cout << "Added Element (" << *element << ") to the rear." << endl;
}

template <class T>
void SingleLinkedList<T>::add(int index, T* element) {
	cout << "Added Element (" << *element << ") after this index: " << index << endl;
}

template <class T>
void SingleLinkedList<T>::addAfter(T* element, T* target) {
	cout << "Added Element (" << *element << ") after: " << *target << endl;
}

/* Removing methods */

template <class T>
T* SingleLinkedList<T>::removeFirst() {
	cout << "Removed the first Element." << endl;
	return NULL;
}

template <class T>
T* SingleLinkedList<T>::removeLast() {
	cout << "Removed the last Element." << endl;
	return NULL;
}

template <class T>
T* SingleLinkedList<T>::remove(T* element) {
	cout << "Removed Element (" << *element << ") from list." << endl;
	return NULL;
}

template <class T>
T* SingleLinkedList<T>::remove(int index) {
	cout << "Removed Element at index: " << index << endl;
	return NULL;
}

/* Set method */

template <class T>
void SingleLinkedList<T>::set(int index, T* element) {
	cout << "Set Element (" << *element << ") at index: " << index << endl;
}

/* Get methods */

template <class T>
T* SingleLinkedList<T>::get(int index) {
	cout << "Retriving Element from index: " << index << endl;
	return NULL;
}

template <class T>
T* SingleLinkedList<T>::first() {
	cout << "Retriving the first Element." << endl;
	return NULL;
}

template <class T>
T* SingleLinkedList<T>::last() {
	cout << "Retriving the last Element." << endl;
	return NULL;
}

/* Misc methods */

template <class T>
int SingleLinkedList<T>::indexOf(T* element) {
	cout << "Retriving index of Element (" << *element << ")." << endl;
	return 0;
}

template <class T>
bool SingleLinkedList<T>::contains(T* element) {
	cout << "List contains Element (" << *element << ")." << endl;
	return false;
}

template <class T>
bool SingleLinkedList<T>::isEmpty() {
	cout << "List is empty." << endl;
	return true;
}

template <class T>
int SingleLinkedList<T>::getSize() {
	cout << "List size is 0." << endl;
	return 0;
}

/* Delete method */

template <class T>
SingleLinkedList<T>::~SingleLinkedList() {
	cout << "List is being destroyed" << endl;
}

#endif // !SINGLE_LINKED_LIST_H