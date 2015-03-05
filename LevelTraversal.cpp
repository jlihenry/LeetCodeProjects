#include <iostream>
#include <vector>
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

typedef TreeNode TreeNode; 

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool rightToLeft = true;
        while (!q.empty())
        {
            stack<TreeNode*> temp;
            vector<int> list;
            while (!q.empty())
            {
                TreeNode *dequeue = q.front();
                temp.push(dequeue);
                list.push_back(dequeue->val);
                q.pop();
            }
            while (!temp.empty())
            {
                TreeNode *node = temp.top();
                if (rightToLeft)
                {
                    if (node->right != NULL) q.push(node->right);
                    if (node->left != NULL) q.push(node->left);
                }
                else
                {
                    if (node->left != NULL) q.push(node->left);
                    if (node->right != NULL) q.push(node->right);
                }
                temp.pop();
            }
            rightToLeft = !rightToLeft;
            result.push_back(list);
        }
        return result;
    }
};

int main()
{
	Solution s;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	root->left = node;
	cout << "Why" << endl;
	vector<vector<int> > result = s.zigzagLevelOrder(root);
	
	return 0;
}
