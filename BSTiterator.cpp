#include <iostream>
#include <stack>
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

class BSTIterator {
    stack<TreeNode*> s;
    
public:
    BSTIterator(TreeNode *root) {
        TreeNode *node = root;
        while (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = s.top();
        TreeNode *next = node->right;
        int value = node->val;
        s.pop();
        while (next != NULL)
        {
            s.push(next);
            next = next->left;
        }
        return value;
    }
};

int main()
{
	TreeNode *root = NULL;
	BSTIterator i = BSTIterator(root);
	cout << "Hello" << endl;
	while (i.hasNext()) cout << i.next();
	return 0;
}
