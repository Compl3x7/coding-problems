// Runtime: 5ms | Beats 34.03% of users
// Memory: 17.83MB | Beats 8.37% of users
// Time complexity: O(n)
// Spacial complexity O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    private:
        TreeNode* popTreeNode(std::stack<TreeNode*> &stack)
        {
            TreeNode *popped = stack.top();
            stack.pop();
            return popped;
        }
    public:
        bool isSymmetric(TreeNode *root) 
        {
            std::stack<TreeNode*> leftStack;
            std::stack<TreeNode*> rightStack;
            leftStack.push(root->left);
            rightStack.push(root->right);

            while (!leftStack.empty() && !rightStack.empty())
            {
                TreeNode *leftPopped = popTreeNode(leftStack);
                TreeNode *rightPopped = popTreeNode(rightStack);

                if (leftPopped == nullptr && rightPopped == nullptr)
                    continue;
                if (leftPopped == nullptr ^ rightPopped == nullptr)                
                    return false;
                if (leftPopped->val != rightPopped->val)
                    return false;

                leftStack.push(leftPopped->left);
                leftStack.push(leftPopped->right);
                rightStack.push(rightPopped->right);
                rightStack.push(rightPopped->left);
            }

            return true;
        }
};
