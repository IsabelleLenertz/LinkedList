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
struct ListNode {
	Boat *data;
	struct ListNode *next;
};
// ListNode

//
// Function Prototype
void appendNode(ListNode *&, Boat*);
void destroyList(ListNode *aNode);
void traverseList(ListNode *aNode);
// Returns true if the node was inserted properly
// Returns false if the position did not exists.
bool insertNode(ListNode *&, Boat*, int);
// Returns the size of the list.
int getSize(ListNode *aNode);
// Returns the position of a node
int findNode(ListNode *aNode, double searchWeight);
// Reverse the list
void  reverseList(ListNode * &headPtr);
// Deletes a node at a specific position (position >1)
// returns true to signify success
// returns false to signify the node was not find.
bool deleteNode(ListNode *&aNode, int position);



//Main Function
int main() {
	ListNode *head = nullptr;
	string userInput = "";
	const int NUMBOAT = 5;
	int listPosition = 0;

	cout << "Creating 100 boats" << endl;
	for (int i = 0; i < NUMBOAT; i++) {
		// Creates a new boat
		Boat *theBoat = new Boat();
		// Sets the weight and model
		theBoat->setWeight((i + 1) * 100);
		theBoat->setModel("boat");
		// Adds them to the end of the list
		appendNode(head, theBoat);
	}

	// Traverse the entire list
	cout << "Getting ready to traverse List" << endl;
	getline(cin, userInput);
	traverseList(head);
	cout << "There are " << getSize(head) << " nodes in the list." << endl;

	cout << "Please enter a position in the list 1-100 to insert the boat after" << endl;
	cin >> listPosition;
	// Creates a new boat
	Boat *theBoat = new Boat();
	// Sets the weight and model
	theBoat->setWeight(998);
	theBoat->setModel("an inserted boat");
	insertNode(head, theBoat, listPosition);

	// Find a position.
	cout << "Ready to find a boat that weighs 998" << endl;
	getline(cin, userInput);
	cout << "Boat found at position " << findNode(head, 998) << endl;

	// Deletes a node
	cout << "position to destroy: " << endl;
	cin >> listPosition;
	getline(cin, userInput);
	deleteNode(head, listPosition);

	// Traverse the entire list
	cout << "Getting ready to traverse List after insert" << endl;
	getline(cin, userInput);
	traverseList(head);


	// Reverses the list
	cout << "Getting ready to reverse the list." << endl;
	getline(cin, userInput);
	reverseList(head);

	// Traverse the entire list
	cout << "Getting ready to traverse List after insert" << endl;
	getline(cin, userInput);
	traverseList(head);


	// Deletes the entire linked list
	cout << "Getting ready to destroy List" << endl;
	getline(cin, userInput);
	destroyList(head);

	return 0;
}

void appendNode(ListNode*&aNode, Boat* theBoat) {

	ListNode *nodePtr;

	// Check if there is something in the first node.
	if (aNode == nullptr) {
		// Dynamically allocate a new node to the head
		aNode = new ListNode;
		// set its
		aNode->data = theBoat;
		aNode->next = nullptr;
	} // if
	  // this is not the first in the list, so we need to find the last
	else {
		// while node ptr has something in is (it it true if it has smth other than null or zero)
		nodePtr = aNode;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}	//while
			// Create a new node after the last of the list
		nodePtr->next = new ListNode;
		// Assigns the boat to that node
		nodePtr->next->data = theBoat;
		// Set the last pointer to nullptr
		nodePtr->next->next = nullptr;
	}		// else
}		// appendNode

void destroyList(ListNode *aNode) {
	ListNode *nodePtr, *tempPtr;

	// Sets a temporary pointer, just because the teacher wants it. But he admitted it is useless and I am right!
	// Sorry, I had to...
	// Have a nice day
	nodePtr = aNode;

	while (nodePtr != nullptr) {
		// remembers address of the next node
		tempPtr = nodePtr->next;

		// Destroys the boat of the current node
		delete nodePtr->data;
		// Destroys the current node
		delete nodePtr;

		// set current pointer to the next node
		nodePtr = tempPtr;
	}		// while

	// Useless, just to please the teacher.
	aNode = nodePtr;
}

void traverseList(ListNode *aNode) {
	ListNode *nodePtr;

	nodePtr=aNode;
	while (nodePtr != nullptr) {
		// remembers address of the next node
		cout << nodePtr->data->whatAmI() << endl;
		nodePtr = nodePtr->next;

	}		// while

}

bool insertNode(ListNode*&aNode, Boat* theBoat, int position){

	// temporary pointer to a node
	ListNode *nodePtr;
	ListNode *tempNode;

	// Check if the list is empty
	if (aNode == nullptr){
		return false;
	}
	else{
		nodePtr = aNode;
	}

	// Goes through the list and make sure the position the user wants to insert a node to exists.
	// Return false if the position does not exist.
	if (position !=0){
		for (int i=0; i < (position-1); i++ ) {
			// check if we do not reach the list
			if (nodePtr->next == nullptr){
				return false;
			}
			else{
				nodePtr = nodePtr->next;
			}
		} // end of for	}
		ListNode *newNode = new ListNode;
		tempNode = nodePtr->next;
		nodePtr->next = newNode;
		newNode->data = theBoat;
		newNode->next = tempNode;
	} // end of if
	else{
		ListNode *newNode = new ListNode;
		tempNode = nodePtr;
		newNode->data = theBoat;
		newNode->next = tempNode;
		aNode = newNode;
	}
	return true;



}// end of insertNode

int getSize(ListNode *aNode) {
	ListNode *nodePtr;
	int size = 0;

	nodePtr=aNode;
	while (nodePtr != nullptr) {
		// remembers address of the next node
		nodePtr = nodePtr->next;
		size++;

	}		// while

	return size;
}

// Returns the position of a node
// Returns 0 if the node was not found
int findNode(ListNode *aNode, double searchWeight){
	ListNode *nodePtr;
	int position = 0;

	nodePtr = aNode;
	while (nodePtr) {
		// remembers address of the next node
		if ( searchWeight == nodePtr->data->getWeight() ){
			// exists the while loop if the weight is found
			break;
		}
		else{
			// keeps track of the position
			position++;
			nodePtr = nodePtr->next;
		}// end of else
	}// while

	if (nodePtr == nullptr)	{
		return 0;
	}
	else {
		return (position+1);
	}

} // end of findNode

void reverseList(ListNode * &headPtr) {
	ListNode *nodePtr;
	ListNode *tempHeadPtr, *temp;

	tempHeadPtr = headPtr ;
	nodePtr = headPtr->next;
	while (nodePtr != nullptr) {
		temp = nodePtr->next;
		nodePtr->next = headPtr;
		headPtr = nodePtr;
		nodePtr = temp;
	}		// while
	tempHeadPtr->next = nullptr;
} // end of reverseList


// Deletes a node at a specific position (position >1)
// returns true to signify success
// returns false to signify the node was not find.
bool deleteNode(ListNode *&aNode, int position){

	// temporary pointer to a node
	ListNode *nodePtr;
	ListNode *prevNode;

	// Initializes the previous node we want to keep track of.
	prevNode = aNode;
	// Check if the list is empty
	if (aNode == nullptr){
		return false;
	}
	else{
		nodePtr = aNode;
	}

	// Goes through the list and make sure the position the user wants to delete a node that exists.
	// Return false if the position does not exist.
	if (position !=0){
		for (int i=0; i < (position-1); i++ ) {
			// check if we do not reach the end list
			if (nodePtr->next == nullptr){
				// returns false if reached the end of the list without finding the position
				return false;
			}
			else{
				// moves to the next node
				prevNode = nodePtr;
				nodePtr = nodePtr->next;
			}
		} // end of for
		// if the user wants to delete the first node
		if (position == 1) {
				// if the user wants to delete the first node and it is the only node.
				if (nodePtr->next == nullptr){
					aNode = nullptr;
				}// end of if
				// if the user wants to delete the first node and it is not the only node.
				else{
					aNode = nodePtr->next;
				}// end of else

		}// end of if
		//If the user wants to delete any other than the first one.
		else{
			// moves to the next node
			prevNode->next = nodePtr->next;
		}// end of else

		// deletes the node and reconnects the two portion of the list.
		prevNode->next = nodePtr->next;
		// deletes the dynamically allocated memory
		delete nodePtr->data;
		delete nodePtr;

	} // end of if
	else{
		// return false if the user wants to delete position 0 (does not exist, we start at 1)
		return false;
	}

	// signifies the node was properly deleted.
	return true;

}

