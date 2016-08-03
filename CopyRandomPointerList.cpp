/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *newcurr = new RandomListNode(head->label);
        newcurr->random = head->random;
        RandomListNode *pre = head;
        RandomListNode *newpre = newcurr;
        RandomListNode *curr = head->next;
        head = newpre;
        while (curr) {
            newcurr = new RandomListNode(curr->label);
            newpre->next = newcurr;
            pre->next = newpre;
            pre = curr;
            curr = curr->next;
            newpre = newcurr;
        }
        pre->next = newpre;
        curr = head;
        while (curr) {
            curr->random = curr->random->next;
            curr = curr->next;
        }
        return head;
    }
};