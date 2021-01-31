// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SinglyLinkedList.h"
#include "LinkedListApplications.h"

int main()
{
	/*SingleLL SLL;
	SLL.SingleLLOperations();*/

	SingleLL SLL1;
	SingleLL::Node * head1 = NULL;
	SingleLL::Node * head2 = NULL;
	SingleLL::Node * head3 = NULL;
	head1 = SLL1.CreateList();
	cout << "List 1:" << endl;
	SLL1.PrintList(head1);

	SingleLL SLL2;
	head2 = SLL2.CreateList();
	cout << "List 2:" << endl;
	SLL2.PrintList(head2);

 	head3 = AddTwoLists(head1, head2);

	cout << "The sum of two lists" << endl;
	SLL2.PrintList(head3);

}


