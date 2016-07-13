#include "Add Two Numbersr.h"
#include <stack>
//add comnets here just for commenting.
using std::stack;
int main()
{
	ListNode *L1 = new ListNode(1);
	//L1->next = new ListNode(7);
	//L1->next->next = new ListNode(3);
	/*L1->next->next->next = nullptr;
	L1->next->next = nullptr;
*/
	ListNode *L2 = new ListNode(9);
	L2->next = new ListNode(9);
	//L2->next->next = new ListNode(4);
	//L2->next->next->next = nullptr;
	Solution s;
	ListNode *result = s.addTwoNumbers(L1, L2);
	stack<int> temp;
	while (result!=nullptr)
	{
		temp.push(result->val);
		result = result->next;
	}
	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
	system("pause");
	return 0;
}