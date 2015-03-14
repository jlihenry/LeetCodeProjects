#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void flatten(TreeNode *root) {
        root=flat(root);
    }
    
    TreeNode *flat(TreeNode *root)
    {
        if (!root) return root;
        if (!root->left && !root->right) return root;
        cout << "test\n";
        TreeNode *left=flat(root->left);
        cout << "test1\n";
        TreeNode *right=flat(root->right);
        cout << "test2\n";
        if (!left) root->right=right;
        else
        {
            root->right=left;
            while (left->right) left=left->right;
            left->right=right;
        }
        return root;
    }
};

int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *right=new TreeNode(2);
	root->right=right;
	Solution s;
	s.flatten(root);
	return 0;
} 
