#include <string>
#include "SingleLinkedList.h"


int main() {
	SingleLinkedList<string> list;

	cout << endl << "-- Adding Methods --" << endl << endl;

	list.addToFront(new string("A"));
	list.addToRear(new string("B"));
	list.add(new string("C"));
	list.add(4, new string("D"));
	list.addAfter(new string("E"), new string("D"));

	cout << endl << "-- Removing Methods --" << endl << endl;

	list.removeFirst();
	list.removeLast();
	list.remove(new string("D"));
	list.remove(0);

	cout << endl << "-- Set Method --" << endl << endl;

	list.set(0, new string("F"));

	cout << endl << "-- Get Methods --" << endl << endl;

	list.get(0);
	list.first();
	list.last();

	cout << endl << "-- Misc Methods --" << endl << endl;

	list.indexOf(new string("F"));
	list.contains(new string("F"));
	list.isEmpty();
	list.getSize();

	cout << endl << "-- Done with Methods --" << endl << endl;

	return 0;
}
