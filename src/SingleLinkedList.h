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

/*
* Adds an element to the rear of a list and assigns tail to it.
* element - Element being added to rear of list.
*/
template <class T>
void SingleLinkedList<T>::addToRear(T* element) {
    //Create a new node with element.
    Node<T>* node = new Node<T>(element, NULL);
    //Check to see if the list is empty, if so, set head as node.
    if(size == 0) {
        head = node;
        tail = head;
    //If not, set the tails next node as the new node
    } else {
        tail->next = node;
    }

    //Move the tail to the new node and increase the size by 1.
    tail = node;
    size++;
	cout << "Added Element (" << *element << ") to the rear (Add to rear method)." << endl;
}

/*
* Adds an element to the rear of a list and assigns tail to it.
* element - Element being added to rear of list.
*/
template <class T>
void SingleLinkedList<T>::add(T* element) {
    Node<T>* node = new Node<T>(element, NULL);

    if(size == 0) {
        head = node;
        tail = head;
    } else {
        tail->next = node;
    }

    tail = node;
    size++;
	cout << "Added Element (" << *element << ") to the rear (Add method)." << endl;
}

/*
* Inserts an element at given index, pushing following elements back.
* index - position in list to insert element.
* element - object or value or be inserted.
* Throws exception of index is invalid.
*/
template <class T>
void SingleLinkedList<T>::add(int index, T* element) {
	if(index < 0 || index > size){
		throw "ERROR: invalid index.";
	}
	if(index == size){
		add(element);
	} else if(index == 0){
		Node<T>* newNode = new Node<T>(element, head);
		head = newNode;
		size++;
	} else {
		Node<T>* current = head;
		for(int i =0; i < index-1; i++){
			current = current->next;
		}
		Node<T>* newNode = new Node<T>(element, NULL);
		Node<T>* temp = current->next;
		current->next = newNode;
		newNode->next = temp;
		size++;
	}
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
/* 
* Removes first element in list.
* Throws exception if list is empty.
*/
template <class T>
T* SingleLinkedList<T>::removeFirst() {
	if(size == 0){
		throw "ERROR: list is empty.";
	}
	Node<T>* placeHolder = head;
	head = head->next;
	size--;
	cout << "Removed the first Element." << endl;
	T* element = placeHolder->data;
	delete placeHolder;
	return element;
}

/* 
* Removes the last element from the list
* Throws exception if list is empty.
*/
template <class T>
T* SingleLinkedList<T>::removeLast() {
	Node<T>* currentNode = head;
	if(size == 0){
		throw "ERROR: list is empty.";
	}
	if(size ==1) {
		tail = head = NULL;
		size--;
		return currentNode->data;
	} else{
		int currentIndex = 0;
		while (currentIndex < size -2){
			currentNode = currentNode->next;
			currentIndex++;
		}
		Node<T>* placeHolder = tail;
		currentNode->next = NULL;
		tail = currentNode;
		size--;
		cout << "Removed the last Element." << endl;
		T* element = placeHolder->data;
		delete placeHolder;
		return element;
	}
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
		currentNode->next = currentNode->next->next;
		delete remove;

		cout << "Removed Element (" << *element << ") from list." << endl;
		return placeHolder;
	}
}

/*
* Removes the element at a given index from the list.
* index- position in list of the element to be removed. 
* Throws exception if index in invalid.
*/
template <class T>
T* SingleLinkedList<T>::remove(int index) {
	if(index < 0 || index >= size) {
		throw "ERROR: invalid index.";
	} else if (index == 0){
		return removeFirst();
	} else if (index == size-1){
		return removeLast();
	} else {
		Node<T>* currentNode = head;
		int currentIndex = 0;
		while(currentIndex != index-1){
			currentNode = currentNode->next;
			currentIndex++;
		}
		Node<T>* placeHolder = currentNode->next;
		currentNode->next = currentNode->next->next;
		size--;
		T* element = placeHolder->data;
		delete placeHolder;
		delete currentNode;
		return element;
	}
}

/* Set method */
/*
*Sets the element of the given index to the given element.
* index- index of element to be set.
* element- value or object to be set. 
* Throws exception if index is invalid.
*/ 

template <class T>
void SingleLinkedList<T>::set(int index, T* element) {
	cout << "Set Element (" << *element << ") at index: " << index << endl;
	if(index < 0 || index >= size) {
		throw "ERROR: Invalid index.";
	}
	Node<T>* node = head;
	for(int i = 0; i < index ; i++) {
		node = node->next;
	}
	node->data = element;
	delete node;
}

/* Get methods */

/*
* Gets the element of the node that index corresponds to.
* index - index of node carrying element you want to get
* Throws a const char* exception if the input index is out of bounds
*/
template <class T>
T* SingleLinkedList<T>::get(int index) {
    if(index < 0 || index >= size) {
        throw "ERROR: Index is out of bounds.";
    }

    Node<T>* node = head;

    for(int i = 0; i < index; i++) {
        node = node->next;
    }
	cout << "Retrieving Element from index: " << index << endl;
	return node->data;
}

/*
* Gets the element of the head node.
* Throws a const char* exception if list is empty
*/
template <class T>
T* SingleLinkedList<T>::first() {
    if(isEmpty) {
        throw "ERROR: List is empty.";
    }
	cout << "Retrieving the first Element." << endl;
	return head->data;
}

/*
* Gets the element of the tail node.
* Throws a const char* exception if list is empty
*/
template <class T>
T* SingleLinkedList<T>::last() {
    if(isEmpty) {
        throw "ERROR: List is empty.";
    }
	cout << "Retrieving the last Element." << endl;
	return tail->data;
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

	cout << "Retrieving index of Element (" << *element << ")." << endl;
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
