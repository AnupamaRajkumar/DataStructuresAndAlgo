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
private:
	/*Defining the node structure*/
	typedef struct SLLNode {
		size_t val;
		struct SLLNode  *next;
	}Node;
	Node *head = NULL;
	Node *current = NULL;
	Node *prev = NULL;
	Node *next = NULL;
	/*Linked list operation functions*/
	void CreateList();
	void InsertNode();
	void InsertAtBegin(size_t val);
	void InsertAtEnd(size_t val);
	void InsertAtPosition(size_t val, int position);
	void DeleteNode();
	void ReverseList();
	size_t DeleteFromBegin();
	size_t DeleteFromEnd();
	size_t DeleteFromPosition(int position);
	void PrintList();
};


#endif // !__SLL__

