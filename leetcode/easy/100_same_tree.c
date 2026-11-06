// Runtime: 0ms | Beats 100.00% of users
// Memory: 12.23MB | Beats 8.01% of users
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL ^ q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
