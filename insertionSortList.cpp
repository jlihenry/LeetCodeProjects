#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *curr = head, *prev = head, *res=NULL;
    	int i = 0;
    	while (curr)
    	{
    		ListNode *next = curr->next;
    		curr->next = NULL;
    		res = insert(res, curr);
    		curr = next;
    	}
    	return res;
    }
    
    ListNode* insert(ListNode *head, ListNode *node)
    {
        ListNode *curr = head, *prev = NULL;
    	if (!curr) return node;
    	while (curr)
    	{
    		if (curr->val > node->val)
    		{
    			if (!prev)
    			{
    				node->next = curr;
    				return node;
    			}
    			else
    			{
    				node->next = prev->next;
    				prev->next = node;
    				return head;
    			}
    		}
    		prev = curr;
    		curr = curr->next;
    	}
    	prev->next = node;
    	return head;
    }
};
