/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode*> my_stack;
        vector<int> result;
        while(1)
        {
            while(root)
            {
                my_stack.push(root);
                root = root->left;
            }
            
            if (my_stack.empty())
                break;
            
            root = my_stack.top();
            my_stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
     
        return result;
    }
};
