#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T* data;
	Node<T>* next;
	
	Node(T* element, Node<T>* next) {
		this->data = element;
		this->next = next;
	}
};

template <class T>
class SingleLinkedList
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
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

/* Constructor */

template <class T>
SingleLinkedList<T>::SingleLinkedList() {
	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
	cout << "Created a List" << endl;
};

/* Adding methods */

/*
* Adds an element to the front of the list.
* element - Element to add to the front of the list.
*/
template <class T>
void SingleLinkedList<T>::addToFront(T* element) {
	Node<T>* node = new Node<T>(element, NULL);
	node->next = head;
	head = node;

	if (size == 0) {
		tail = head;
	}

	size++;
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

/*
* Adds an element after the target provided.
* element - Element to add after target provided.
* target - Target to add element after.
* throws a const char* exception when the target 
* isn't found within the list.
*/
template <class T>
void SingleLinkedList<T>::addAfter(T* element, T* target) {
	Node<T>* currentNode = head;
	bool foundIt = false;

	while (currentNode != NULL && !foundIt) {
		if (*(currentNode->data) == *target)
			foundIt = true;
		else
			currentNode = currentNode->next;
	}

	if (!foundIt)
		throw "ERROR: The element wasn't found in the list.";

	Node<T>* newNode = new Node<T>(element, currentNode->next);
	currentNode->next = newNode;

	size++;

	if (currentNode == tail)
		tail = newNode;

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

/*
* Removes an element from the list.
* element - Element to remove from the list.
* Throws a const char* exception if list is empty 
* or element wasn't found in the list.
*/
template <class T>
T* SingleLinkedList<T>::remove(T* element) {
	if (size == 0) {
		throw "ERROR: List is Empty.";
	}else if (*(head->data) == *element) {
		return removeFirst();
	}else if (*(tail->data) == *element) {
		return removeLast();
	}else {
		Node<T>* currentNode = head;
		bool foundIt = false;

		while (!foundIt && currentNode->next != NULL) {
			if (*(currentNode->next->data) == *element)
				foundIt = true;
			else
				currentNode = currentNode->next;
		}

		if (!foundIt)
			throw "ERROR: The element wasn't found in the list.";

		size--;

		Node<T>* remove = currentNode->next;
		T* placeHolder = remove->data;
		delete remove;

		currentNode->next = currentNode->next->next;

		cout << "Removed Element (" << *element << ") from list." << endl;
		return placeHolder;
	}
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

/*
* Finds an elements position within the list.
* element - Element to find location.
* Returns a -1 if the element was not found in the list.
*/
template <class T>
int SingleLinkedList<T>::indexOf(T* element) {
	Node<T>* currentNode = head;
	int loc = 0;

	while (currentNode != NULL  && *(currentNode->data) != *element) {
		currentNode = currentNode->next;
		loc++;
	}

	cout << "Retriving index of Element (" << *element << ")." << endl;
	if (currentNode == NULL)
		return -1;
	else
		return loc;
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

/*
* Deletes this list preventing memory leakage.
*/
template <class T>
SingleLinkedList<T>::~SingleLinkedList() {
	Node<T>* currentNode = head;
	while (currentNode != NULL) {
		Node<T>* prev = currentNode;
		currentNode = currentNode->next;
		delete prev->data;
		delete prev;
	}
	cout << "List is being destroyed" << endl;
}

#endif // !SINGLE_LINKED_LIST_H