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
void appendNode(ListNode *, Boat*);
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
		theBoat->setModel("A Boat");
		// add them to the end of the list
		appendNode(head, theBoat);
	}

	// Deletes the entire linked list
	destroyList(head);

	return 0;
}

void appendNode(ListNode*aNode, Boat* theBoat){

	ListNode *nodePtr;

	// Check if there is something in the first node.
	if (aNode == nullptr){
		aNode->data = theBoat;
	}// if
	// this is not the first in the list, so we need to find the last
	else {
		// while node ptr has something in is (it it true if it has smth other than null or zero)
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}//while
		nodePtr->next = aNode;
		aNode->next = nullptr;
	}// else
}// appendNode

void destroyList(ListNode *aNode){
	ListNode *nodePtr, *tempPtr;

	nodePtr = aNode;
	while (nodePtr){
		tempPtr = nodePtr->next;
		delete nodePtr->data;
		delete nodePtr;
		nodePtr = tempPtr;
	}// while

	aNode = nodePtr;
}
