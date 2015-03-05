#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        /* Get length of the list */
        int len=0;
		ListNode *scan=head;
        while (head)
        {
            len++;
			cout << "Node " << len << ": " << head->val << endl; 
            head=head->next;
        }
		head=scan;
        
        /* Sort the list recursively */
        if (len==0) return NULL;
        else if (len==1) return head;
        else if (len==2)
        {
            if (head->val>head->next->val)
            {
                return head;
                ListNode *res=head->next;
                head->next->next=head;
                head->next=NULL;
                return res;
            }
            else return head;
        }
        else
        {
            ListNode *l1=head, *prev;
            for (int i=0; i<len/2; i++) 
			{
				prev=head;
				head=head->next;
			}
			prev->next=NULL;
            ListNode *l2=head;
			cout << "The pre-half list starts from " << l1->val << endl;
			cout << "The post-half list starts from " << l2->val << endl;
            return mergeSortedList(sortList(l1), sortList(l2));
        }
    }
    
    ListNode *mergeSortedList(ListNode *l1, ListNode *l2)
    {
        if (!l1&&!l2) return NULL;
        else if (!l1) return l2;
        else if (!l2) return l1;
        else
        {
            ListNode *curr=(l1->val>l2->val)?l2:l1;
            ListNode *ptr=(l1->val>l2->val)?l1:l2;
            ListNode *head=curr;
            while (curr)
            {
                if (!curr->next)
                {
                    curr->next=ptr;
                    return head;
                }
                else if (!ptr)
                {
                    return head;
                }
                else
                {
                    if (curr->next->val>ptr->val)
                    {
                        ListNode *tmp=curr->next;
                        curr->next=ptr;
                        ptr=tmp;
                    }
                    else
                    {
                        curr=curr->next;
                    }
                }
            }
        }
    }
};

int main()
{
	Solution s;
	ListNode *head=new ListNode(3);
	ListNode *mid=new ListNode(2);
	ListNode *tail=new ListNode(4);
	head->next=mid;
	mid->next=tail;
	head=s.sortList(head);
	return 0;
}

