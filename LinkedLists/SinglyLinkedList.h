#pragma once
#ifndef __SLL__
#define __SLL__

#include<iostream>
using namespace std;

class SingleLL
{
public:
	SingleLL();
	void SingleLLOperations();
	/*Defining the node structure*/
	typedef struct SLLNode {
		size_t val;
		struct SLLNode  *next;
	}Node;
	/*Linked list operation functions*/
	Node* CreateList();
	Node* InsertNode(Node*);
	Node* InsertAtBegin(size_t val, Node* head);
	void InsertAtEnd(size_t val, Node* head);
	Node* InsertAtPosition(size_t val, int position, Node* head);
	Node* DeleteNode(Node*);
	Node* DeleteFromBegin(Node* head, int& val);
	void DeleteFromEnd(Node* head, int& val);
	Node* DeleteFromPosition(int position, Node* head, int& val);
	Node* ReverseList(Node*);
	void PrintList(Node* head);
	int ListLength(Node* head);

private:
	Node *head = NULL;
	Node *current = NULL;
	Node *prev = NULL;
	Node *next = NULL;
};


#endif // !__SLL__

