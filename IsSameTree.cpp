#include<iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        else if ((!p && q) || (!q && p)) 
		{
			cout << "one is null and the other is not" << endl;
			return false;	
		}
        else
        {
        	cout << "both are not null" << endl;
            if (p->val != q->val) return false;
            else return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
        }
    }
};

int main()
{
	TreeNode *p = new TreeNode(1);
	TreeNode *q = NULL;
	Solution s;
	s.isSameTree(p, q);
	return 0;
} 
