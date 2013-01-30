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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> my_stack;
		
		while(1)
		{
			while(root)
			{
				result.push_back(root->val);
				my_stack.push(root);
				root = root->left;
			}
			
			if(my_stack.empty())
				break;
			root = my_stack.top();
			my_stack.pop();
			root = root->right;
		}
		
		return result;
	}
	
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
	
	/*
1) Push the root node to the child stack.
2) while child stack is not empty
		Pop a node from the child stack, and push it to the parent stack.
		Push its left child followed by its right child to the child stack.
	end while
3) Now the parent stack would have all the nodes ready to be traversed in post-order. 
   Pop off the nodes from the parent stack one by one and you will have the post order traversal of the tree.	
   */
	vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> result;
	stack<TreeNode*> parent_stack;
	stack<TreeNode*> child_stack;

	if (root)
        {
    		child_stack.push(root);
    		
    		while(child_stack.empty() == false)
    		{
    			TreeNode* temp = child_stack.top();
    			child_stack.pop();
    			parent_stack.push(temp);
    			
                if (temp->left != NULL)
    			    child_stack.push(temp->left);
    			if(temp->right != NULL)
                    child_stack.push(temp->right);
    		}
    		
    		while(parent_stack.empty() == false)
    		{
    			result.push_back(parent_stack.top()->val);
    			parent_stack.pop();
    		}
        }
	return result;
	}

	/*
	while visiting nodes of level l, keep all nodes at l+1 level in the queue.
	*/
    	vector<int> levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        queue<TreeNode*> my_queue;
        
        if(root)
        {
            my_queue.push(root);
            
            while(my_queue.empty() == false)
            {
                TreeNode* temp = my_queue.front();
                result.push_back(temp->val);
                my_queue.pop();
                if(temp->left != NULL)
                    my_queue.push(temp->left);
                if(temp->right != NULL)
                    my_queue.push(temp->right);
            }
        }
        
        return result;
        
    	}
};
