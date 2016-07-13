//This is a different method written by Jackie Tao long time ago.
#include <iostream>
struct ListNode{
public:
	ListNode(int node_value) :val(node_value), next(nullptr){}
	ListNode *next;
	//private:
	int val;
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL){
			return l1 == NULL ? l2 : l1;
		}
		size_t len1 = 0;
		size_t len2 = 0;
		ListNode* pHead = l1;
		while (pHead != NULL)
		{
			++len1;
			pHead = pHead->next;
		}
		pHead = l2;
		while (pHead != NULL)
		{
			++len2;
			pHead = pHead->next;
		}

		//use pHead to store the long Linked_List.
		//use pShort to store the short Linked_List.
		ListNode *pLong = NULL;
		ListNode *pShort = NULL;
		if (len1 <= len2)
		{
			pLong = l2;
			pShort = l1;
		}
		else
		{
			pLong = l1;
			pShort = l2;
		}
		//use pHead to store the return Linked_List.
		pHead = pLong;
		//to judge whether there is a carry.
		bool carry = false;
		ListNode* previous = NULL;
		while (pLong != NULL&&pShort != NULL)
		{
			int sum = 0;
			//if there is a carray,sum equals the total value add 1. Or just the value.
			sum = carry ? (pShort->val + pLong->val + 1) : (pShort->val + pLong->val);
			if (sum >= 10)
			{
				sum -= 10;
				carry = true;
				pLong->val = sum;
			}
			else
			{
				pLong->val = sum;
				carry = false;
			}
			previous = pLong;
			pLong = pLong->next;
			pShort = pShort->next;
		}
		if (pLong == NULL&&carry) {
			ListNode *new_node = new ListNode(1);
			previous->next = new_node;
			new_node->next = NULL;
		}
		while (pLong != NULL&&carry)
		{
			pLong->val += 1;
			if (pLong->val >= 10)
			{
				pLong->val -= 10;
				carry = true;
				//pLong is the last node.
				previous = pLong;
				if (pLong->next == NULL) {
					ListNode *new_node = new ListNode(1);
					previous->next = new_node;
					new_node->next = NULL;
					break;
				}
				pLong = pLong->next;
			}
			else
			{
				carry = false;
			}
		}
		return pHead;
	}
};