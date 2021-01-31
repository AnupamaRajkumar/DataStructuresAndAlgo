
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
	Node* head = NULL;
	do {
		cout << "Single Linked List Menu" << endl;
		cout << "1. Create a linked list" << endl;
		cout << "2. Insert an element in the list" << endl;
		cout << "3. Delete an element from the list" << endl;
		cout << "4. Display the list" << endl;
		cout << "5. Reverse the list" << endl;
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			head = this->CreateList();
			break;
		case 2:
			head = this->InsertNode(head);
			break;
		case 3:
			head = this->DeleteNode(head);
			break;
		case 4:
			this->PrintList(head);
			break;
		case 5 : 
			head = this->ReverseList(head);
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
Returns		: Pointer to the head node
Function	: This function creates a single linked list. User can keep
			  on adding values to the list 
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/
SingleLL::Node* SingleLL::CreateList() {
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
	this->PrintList(head);
	return head;
}

/*************************************************************************
Name		: InsertNode()
Parameters	: Pointer to the head node
Returns		: Pointer to the new head node after insertion
Function	: This function displays the menu for inserting nodes at various
			  locations that can be chosen from a user menu
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::InsertNode(SingleLL::Node* head) {
	int choice;
	size_t val;
	int position, listLen;
	Node* headNew;
	headNew = head;
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
		headNew = this->InsertAtBegin(val, head);
		break;
	case 2:
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		this->InsertAtEnd(val, head);
		break;
	case 3:
		cout << "Enter the value to be inserted" << endl;
		cin >> val;
		cout << "Enter the position to insert the node at" << endl;
		cin >> position;
		listLen = this->ListLength(head);
		if (position > 0 && position <= listLen) {
			headNew = this->InsertAtPosition(val, position, head);
		}
		else {
			cerr << "The position must be greater than 0 and less than or equal to " << listLen << endl;
		}
		break;
	default:
		cerr << "Kindly enter valid choice" << endl;
		break;
	}
	this->PrintList(headNew);
	return headNew;
}

/*************************************************************************
Name		: InsertAtBegin()
Parameters	: value to be inserted, Pointer to the head node
Returns		: Pointer to the new head node after insertion
Function	: This function inserts the value at the beginning of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::InsertAtBegin(size_t val, SingleLL::Node* head) {
	/*Inserting new node at the beginning of the list to create a new head*/
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = head;
	head = newNode;
	return head;
}

/*************************************************************************
Name		: InsertAtEnd()
Parameters	: value to be inserted, pointer to the head node
Returns		: Nothing
Function	: This function inserts the value at the end of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::InsertAtEnd(size_t val, SingleLL::Node* head) {
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
Parameters	: value to be inserted, position at which to be inserted, 
			  pointer to the head node
Returns		: Pointer to the new head node after insertion
Function	: This function inserts the value at the specified location
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::InsertAtPosition(size_t val, int position, SingleLL::Node* head) {
	/*Inserting the new node after the position specified*/
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *ptr = head;
	int count = 1;	//we consider the head position as the first position
	if (position == 1) {
		newNode = this->InsertAtBegin(val, head);
	}
	else {
		while ((count < position) && (ptr->next != NULL)) {
			ptr = ptr->next;
			count++;
		}
		newNode->val = val;
		newNode->next = ptr->next;
		ptr->next = newNode;
	}

	if (position == 1) {
		return newNode;
	}
	else {
		return head;
	}
}

/*************************************************************************
Name		: DeleteNode()
Parameters	: Pointer to the head node
Returns		: Poiter to the new head node after deletion
Function	: This function displays the menu for deleting nodes at various
			  locations that can be chosen from a user menu
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::DeleteNode(SingleLL::Node* head) {
	int choice = 1;
	int val = 0;
	int position;
	int listLen = 0;
	Node* headNew;
	headNew = head;
	cout << "List deletion menu" << endl;
	cout << "1. Delete from the beginning" << endl;
	cout << "2. Delete from the end of the list" << endl;
	cout << "3. Delete from a specific given position" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		headNew = this->DeleteFromBegin(head, val);
		break;
	case 2:
		this->DeleteFromEnd(head, val);
		break;
	case 3:
		cout << "Enter the position to delete the node at" << endl;
		cin >> position;
		listLen = this->ListLength(head);
		if (position <= listLen && position > 0) {
			headNew = this->DeleteFromPosition(position, head, val);
		}
		else {
			cerr << "Position number should be greater than 0 and less than or equal to " << listLen << endl;
		}
		break;
	default:
		cerr << "Kindly enter valid choice" << endl;
		break;
	}
	cout << "Deleted value is:" << val << endl;
	this->PrintList(headNew);
	return headNew;
}

/*************************************************************************
Name		: DeleteFromBegin()
Parameters	: Pointer to the head node, value of the deleted node
Returns		: Pointer to the new head node after node deletion
Function	: This function deletes the value from the beginning of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::DeleteFromBegin(SingleLL::Node* head, int& val) {
	/*delete the head node and make the next node as the new head*/
	if (head != NULL) {
		Node *prevHead;
		val = head->val;
		prevHead = head;
		head = head->next;
		free(prevHead);
		return head;
	}
	else {
		val = NULL;
		cerr << "Empty list, nothing to delete" << endl;
		return 0;
	}
}


/*************************************************************************
Name		: DeleteFromEnd()
Parameters	: Pointer to the head node, value of the deleted node
Returns		: Nothing
Function	: This function deletes the last value of the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

void SingleLL::DeleteFromEnd(SingleLL::Node* head, int& val) {
	/*delete the last node and make the penultimate node as the last node*/
	Node *ptr, *prevPtr;
	if (head != NULL) {
		ptr = head;
		prevPtr = head;
		while (ptr->next != NULL) {
			prevPtr = ptr;
			ptr = ptr->next;
		}
		prevPtr->next = NULL;
		val = ptr->val;
		free(ptr);
	}
	else {
		val = NULL;
		cerr << "Empty list, nothing to delete" << endl;
		exit(0);
	}
}

/*************************************************************************
Name		: DeleteFromPosition()
Parameters	: position, pointer to the head node, value of deleted node
Returns		: Pointer to the new head node after deletion
Function	: This function deletes the value from the specified position in
			  the list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::DeleteFromPosition(int position, SingleLL::Node* head, int& val) {
	Node *ptr, *prevPtr;
	if (head != NULL) {
		ptr = head;
		prevPtr = head;
		int count = 1;	//we consider the head position as the first position
		if (position == 1) {
			head = this->DeleteFromBegin(head, val);
		}
		else {
			while ((count < position) && (ptr->next != NULL)) {
				prevPtr = ptr;
				ptr = ptr->next;
				count++;
			}
			val = ptr->val;
			prevPtr->next = ptr->next;
			ptr->next = NULL;
			free(ptr);
		}
		return head;
	}
	else {
		val = NULL;
		cerr << "Empty list, nothing to delete" << endl;
		return 0;
	}	
}

/*************************************************************************
Name		: PrintList()
Parameters	: Pointer to the head node
Returns		: Nothing
Function	: This function displays the value stored in the linked list
Author		: Anupama Rajkumar
Date		: 20.01.2020
***************************************************************************/
void SingleLL::PrintList(SingleLL::Node* head) {
	if (head != 0) {
		Node *ptr = head;
		while (ptr != NULL) {
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	else {
		cerr << "Empty list" << endl;
	}
}

/*************************************************************************
Name		: ReverseList()
Parameters	: Pointer to the head node
Returns		: Pointer to the new head node
Function	: This function reverses the linked list
Author		: Anupama Rajkumar
Date		: 30.01.2020
***************************************************************************/

SingleLL::Node* SingleLL::ReverseList(SingleLL::Node* head) {
	prev = NULL;
	current = head;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	cout << "The reversed list is:" << endl;
	this->PrintList(head);
	return head;
}

/*************************************************************************
Name		: ListLength()
Parameters	: Pointer to the head node
Returns		: Length of the list
Function	: This function returns the length of the list
Author		: Anupama Rajkumar
Date		: 31.01.2020
***************************************************************************/

int SingleLL::ListLength(SingleLL::Node* head) {
	int cnt = 0;
	if (head != NULL) {
		Node* ptr = head;
		while (ptr != NULL) {
			cnt += 1;
			ptr = ptr->next;
		}
	}
	else {
		cerr << "Empty list" << endl;
	}
	return cnt;
}