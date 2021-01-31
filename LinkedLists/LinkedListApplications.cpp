#include "LinkedListApplications.h"

/***************Operation Definitions*********************/

/*************************************************************************
Name		: AddTwoLists()
Parameters	: Pointer to the head node of list 1
			  Pointer to the head node of list 2
Returns		: Pointer to the head node of the new list 
Function	: This function adds two lists and stores in a new list
Author		: Anupama Rajkumar
Date		: 31.01.2020
***************************************************************************/
/****************************************************************************
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Example:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*****************************************************************************/

SingleLL::Node* AddTwoLists(SingleLL::Node* head1, SingleLL::Node* head2) {
	SingleLL::Node* ptr1 = head1;
	SingleLL::Node* ptr2 = head2;
	SingleLL::Node* ptr3 = NULL;;
	SingleLL::Node* prev = NULL;
	SingleLL::Node* head3 = NULL;
	int cnt = 1;
	int sum = 0, rem = 0, div = 0;
	while (ptr1 != NULL || ptr2 != NULL) {
		int val1 = 0, val2 = 0;
		if (ptr1 != NULL) {
			val1 = ptr1->val;
			ptr1 = ptr1->next;
		}
		if (ptr2 != NULL) {
			val2 = ptr2->val;
			ptr2 = ptr2->next;
		}

		sum = val1 + val2 + div;
		rem = sum % 10;
		ptr3 = (SingleLL::Node *)malloc(sizeof(SingleLL::Node));
		ptr3->val = rem;	
		div = sum / 10;
		if (cnt == 1) {
			head3 = ptr3;
			prev = ptr3;
			ptr3->next = NULL;
		}
		else {
			prev->next = ptr3;
			prev = ptr3;
		}
		cnt += 1;
	}
	//if div is not 0, add another node and assign the value of div
	if (div > 0) {
		ptr3 = (SingleLL::Node *)malloc(sizeof(SingleLL::Node));
		ptr3->val = div;
		prev->next = ptr3;
		prev = ptr3;
	}
	ptr3->next = NULL;
	return head3;
}

