// Runtime: 5ms | Beats 49.45% of users
// Memory: 7.99MB | Beats 100.00% of users
// Time complexity: O(n)
// Spacial complexity O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) 
{
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left) + 1;
    int rightDepth = maxDepth(root->right) + 1;

    return leftDepth > rightDepth ? leftDepth : rightDepth;    
}
