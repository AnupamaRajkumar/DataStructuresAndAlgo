
#include "SinglyLinkedList.h"

/*************************************************************************
Name		: SingleLLOperations()
Parameters	: None
Returns		: Nothing
Function	: This function displays the menu for various operations related
			  to single linked list. User can enter a choice as desired in
			  the user prompt
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/
void SingleLL::SingleLLOperations() {
	int choice, response = 1;
	do {
		cout << "Single Linked List Menu" << endl;
		cout << "1. Create a linked list" << endl;
		cout << "2. Insert an element in the list" << endl;
		cout << "3. Delete an element from the list" << endl;
		cout << "4. Display the list" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			this->CreateList();
			break;
		case 2:
			this->InsertNode();
			break;
		case 3:
			this->DeleteNode();
			break;
		case 4:
			this->PrintList();
			break;
		default:
			cerr << "Please enter a valid choice" << endl;
			break;
		}
		cout << "Do you want to continue? (1 for yes, 0 for no)" << endl;
		cin >> response;
	} while (response != 0);
}

/*************************************************************************
Name		: Constructor
Parameters	: None
Returns		: Nothing
Function	: The constructor initialises the head node of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::SingleLL() {
	cout << "Initialising head node" << endl;
	size_t val;
	cout << "Enter the value for head node" << endl;
	cin >> val;
	this->head = new Node();
	head->val = val;
	head->next = NULL;
}

/*************************************************************************
Name		: CreateList()
Parameters	: None
Returns		: Nothing
Function	: This function creates a single linked list. User can keep
			  on adding values to the list 
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/
void SingleLL::CreateList() {
	int response = 1;
	int cnt = 1;
	do {
		int val;
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		Node *newNode = (Node *)malloc(sizeof(Node));
		/*if it is the first node after head, assign the next of head as the new node*/
		if (cnt == 1) {
			newNode->val = val;
			head->next = newNode;
			newNode->next = NULL;	
		}
		else {
			newNode->val = val;
			this->current->next = newNode;
			newNode->next = NULL;
		}
		this->current = newNode;
		cout << "Node added" << endl;
		cout << "Do you want to continue adding more nodes? (1 for yes, 0 for no)" << endl;
		cin >> response;
		cnt++;
	} while (response != 0);

	/*display the created list*/
	this->PrintList();
}

/*************************************************************************
Name		: InsertNode()
Parameters	: None
Returns		: Nothing
Function	: This function displays the menu for inserting nodes at various
			  locations that can be chosen from a user menu
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::InsertNode() {
	int choice;
	size_t val;
	int position;
	cout << "List insertion menu" << endl;
	cout << "1. Add at the beginning" << endl;
	cout << "2. Add at the end of the list" << endl;
	cout << "3. Add after a specific given position" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		this->InsertAtBegin(val);
		break;
	case 2:
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		this->InsertAtEnd(val);
		break;
	case 3:
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		cout << "Enter the position to insert the node at" << endl;
		cin >> position;
		this->InsertAtPosition(val, position);
		break;
	default:
		cerr << "Kindly enter valid choice" << endl;
		break;
	}
	this->PrintList();
}

/*************************************************************************
Name		: InsertAtBegin()
Parameters	: value to be inserted
Returns		: Nothing
Function	: This function inserts the value at the beginning of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::InsertAtBegin(size_t val) {
	/*Inserting new node at the beginning of the list to create a new head*/
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = head;
	head = newNode;
}

/*************************************************************************
Name		: InsertAtEnd()
Parameters	: value to be inserted
Returns		: Nothing
Function	: This function inserts the value at the end of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::InsertAtEnd(size_t val) {
	/*Inserting the new node at the end of the list*/
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *ptr = head;
	/*reach the end of the list*/
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	/*add the new node once reached the end of the list*/
	newNode->val = val;
	ptr->next = newNode;
	newNode->next = NULL;
}

/*************************************************************************
Name		: InsertAtPosition()
Parameters	: value to be inserted, position at which to be inserted
Returns		: Nothing
Function	: This function inserts the value at the specified location
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::InsertAtPosition(size_t val, int position) {
	/*Inserting the new node after the position specified*/
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *ptr = head;
	int count = 1;	//we consider the head position as the first position
	while ((count < position) && (ptr->next != NULL)) {
		ptr = ptr->next;
		count++;
	}
	newNode->val = val;
	newNode->next = ptr->next;
	ptr->next = newNode;
}

/*************************************************************************
Name		: DeleteNode()
Parameters	: None
Returns		: Nothing
Function	: This function displays the menu for deleting nodes at various
			  locations that can be chosen from a user menu
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::DeleteNode() {
	int choice;
	size_t val;
	int position;
	cout << "List deletion menu" << endl;
	cout << "1. Delete from the beginning" << endl;
	cout << "2. Delete from the end of the list" << endl;
	cout << "3. Delete from a specific given position" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		val = this->DeleteFromBegin();
		break;
	case 2:
		val = this->DeleteFromEnd();
		break;
	case 3:
		cout << "Enter the position to delete the node at" << endl;
		cin >> position;
		val = this->DeleteFromPosition(position);
		break;
	default:
		cerr << "Kindly enter valid choice" << endl;
		break;
	}
	cout << "Deleted value is:" << val << endl;
	this->PrintList();
}

/*************************************************************************
Name		: DeleteFromBegin()
Parameters	: none
Returns		: value deleted
Function	: This function deletes the value from the beginning of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

size_t SingleLL::DeleteFromBegin() {
	/*delete the head node and make the next node as the new head*/
	size_t val;
	Node *prevHead;
	val = head->val;
	prevHead = head;
	head = head->next;
	free(prevHead);
	return val;
}


/*************************************************************************
Name		: DeleteFromEnd()
Parameters	: none
Returns		: value deleted
Function	: This function deletes the last value of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

size_t SingleLL::DeleteFromEnd() {
	/*delete the last node and make the penultimate node as the last node*/
	size_t val;
	Node *ptr, *prevPtr;
	ptr = head;
	prevPtr = head;
	while (ptr->next != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
	}
	prevPtr->next = NULL;
	val = ptr->val;
	free(ptr);

	return val;
}

/*************************************************************************
Name		: DeleteFromPosition()
Parameters	: position
Returns		: value deleted
Function	: This function deletes the value from the specified position in
			  the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

size_t SingleLL::DeleteFromPosition(int position) {
	size_t val;
	Node *ptr, *prevPtr;
	ptr = head;
	prevPtr = head;
	int count = 1;	//we consider the head position as the first position
	while ((count < position) && (ptr->next != NULL)) {
		prevPtr = ptr;
		ptr = ptr->next;
		count++;
	}
	val = ptr->val;
	prevPtr->next = ptr->next;
	ptr->next = NULL;
	free(ptr);

	return val;
}

/*************************************************************************
Name		: PrintList()
Parameters	: None
Returns		: Nothing
Function	: This function displays the value stored in the linked list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/
void SingleLL::PrintList() {
	Node *ptr = head;
	while (ptr->next != NULL) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
