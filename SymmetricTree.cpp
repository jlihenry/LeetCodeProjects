/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode*> s, t;
        s.push(root);
        t.push(root);
        TreeNode *prev = NULL;
        TreeNode *prevt = NULL;
        while (!s.empty() && !t.empty())
        {
            TreeNode *curr = s.top();
            if (!prev || prev->left==curr || prev->right==curr)
            {
                if (curr->left) s.push(curr->left);
                else
                {
                    s.pop();
                    if (curr->right) s.push(curr->right);
                }
            }
            else
            {
                s.pop();
                if (curr->right) s.push(curr->right);
            }
            prev = curr;
            
            curr = t.top();
            if (!prevt || prevt->left==curr || prevt->right== curr)
            {
                if (curr->right) t.push(curr->right);
                else
                {
                    t.pop();
                    if (curr->left) t.push(curr->left);
                }
            }
            else
            {
                t.pop();
                if (curr->left) t.push(curr->left);
            }
            prevt = curr;
            
            if (s.empty() && t.empty()) return true;
            else if (s.empty() && !t.empty() || !s.empty() && t.empty()) return false;
            else if ((s.top())->val != (t.top())->val) return false;
        }
        
    }
};
