//============================================================================
// Name        : LinkedList.cpp
// Author      : Isabelle Delmas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Boat.hpp"

using namespace std;

//
// Linked list Node
struct ListNode{
	Boat *data;
	struct ListNode *next;
};// ListNode

//
// Function Prototype
void appendNode(ListNode *&, Boat*);
void destroyList(ListNode *aNode);

//Main Function
int main() {
	ListNode *head = nullptr;

	cout << "Creating 100 boats" << endl ;
	for (int i = 0; i<100; i++){
		// Creates a new boat
		Boat *theBoat = new Boat();
		// Set the weight and model
		theBoat->setWeight( (i+1)*100 );
		theBoat->setModel("boat");
		cout << theBoat->whatAmI() << endl;
		// add them to the end of the list
		appendNode(head, theBoat);
	}

	// Deletes the entire linked list
	destroyList(head);

	return 0;
}

void appendNode(ListNode*&aNode, Boat* theBoat){

	ListNode *nodePtr;

	// Check if there is something in the first node.
	if (aNode == nullptr){
		// Dinalically alcate a new node to the head
		aNode = new ListNode;
		// set its
		aNode->data = theBoat;
		aNode->next = nullptr;
	}// if
	// this is not the first in the list, so we need to find the last
	else {
		// while node ptr has something in is (it it true if it has smth other than null or zero)
		nodePtr = aNode;
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}//while
		// Create a new node after the last of the list
		nodePtr->next = new ListNode;
		// Assigns the boat to that node
		nodePtr->next->data = theBoat;
		// Set the last pointer to nullptr
		nodePtr->next->next = nullptr;
	}// else
}// appendNode

void destroyList(ListNode *aNode){
	ListNode *nodePtr, *tempPtr;

	// Sets a temporary pointer, just because the teacher wants it. But he admitted it is useless and I am right!
	nodePtr = aNode;

	while (nodePtr != nullptr){
		// remembers address of the next node
		tempPtr = nodePtr->next;

		// Destroys the current node
		delete nodePtr->data;
		delete nodePtr;
		nodePtr = tempPtr;
	}// while

	aNode = nodePtr;
}





