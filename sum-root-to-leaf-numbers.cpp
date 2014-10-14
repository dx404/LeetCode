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
    int sumNumbers(TreeNode *root) {
       return dfs(root, 0);
    }
    
    int dfs(TreeNode *node, int upSum) {
        if (node == nullptr)
            return 0;
        int curSum = 10*upSum + node->val;
        if (node->left == nullptr && node->right == nullptr)
            return curSum;
        return dfs(node->left, curSum) + dfs(node->right, curSum);
    }
};