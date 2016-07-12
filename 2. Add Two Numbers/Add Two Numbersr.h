/*
	You are given two linked lists representing two non-negative numbers. 
	The digits are stored in reverse order and each of their nodes contain a single digit. 
	Add the two numbers and return it as a linked list.
	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8

	Actually, this kind of add operation is just fits to the habit of adding operation.
	We can just add from the beginning of the list to the end of it.
*/

//Define the linkedlist structre.
#include <iostream>
struct ListNode{
public:
	ListNode(int node_value) :val(node_value),next(nullptr){}
	ListNode *next;
//private:
	int val;
};

class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		unsigned len1 = 0, len2=0;
		ListNode *p = l1;
		//Get the length of LinkNode list l1;
		while (p != nullptr)
		{
			++len1;
			p = p->next;
		}
		p = l2;
		while (p != nullptr)
		{
			++len2;
			p = p->next;
		}
		ListNode *q = nullptr;

		//p always points to the longer LinkedList.
		//q points to the shorter one.
		if (len1 >=len2)
		{
			p = l1;
			q = l2;
		}
		else
		{
			p = l2;
			q = l1;
		}
		//Use carry for the specification of carrying.
		ListNode *result = p;
		bool carry = false;
		while (p != nullptr&&q != nullptr)
		{
			if ((p->val + q->val) >= 10)
			{
				if (!carry)
				{
					p->val = (p->val + q->val) % 10;
					carry = true;
				}
				else
					p->val = (p->val + q->val) % 10 + 1;
			}
			else if (carry)
			{
				p->val = p->val + q->val + 1;
				carry = false;
			}
			else
				p->val += q->val;
			if (q->next == nullptr)
			{
				if (p->next == nullptr&&carry)
					p->next = new ListNode(1);
				else if (p->next != nullptr&&carry)
				{
				}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		return result;
	}
};
