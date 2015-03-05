#include <iostream>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ptr1=l1, *ptr2=l2, *head=NULL, *curr=NULL, *prev=NULL;
    int flag=0;
    while (!ptr1 && !ptr2)
    {
        curr = new ListNode((ptr1->val+ptr2->val)%10+flag);
        flag = (ptr1->val+ptr2->val)/10;
        if (prev) prev->next = curr;
        else head = curr;
        prev = curr;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        cout << curr->val << endl;
    }
    cout << "here" << endl;
    if (ptr1) prev->next = ptr1;
    if (ptr2) prev->next = ptr2;
    return head;
}

int main()
{
	ListNode *l1=new ListNode(0);
	ListNode *l2=new ListNode(0);
	ListNode *root = addTwoNumbers(l1, l2);
	return 0;
}
