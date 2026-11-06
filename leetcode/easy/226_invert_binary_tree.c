// Runtime: 1ms | Beats 51.13% of users
// Memory: 5.91MB | Beats 100.00% of users
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
struct TreeNode* invertTree(struct TreeNode *root) 
{
    if (root != NULL)
    {
        struct TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}
