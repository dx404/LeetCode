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
    //pre-order
    TreeNode *parentNode = new TreeNode(-1);
    void flatten(TreeNode *node) {
        if (node == nullptr)
            return;
        TreeNode *left = node->left;
        TreeNode *right = node->right;
            
        parentNode->left = nullptr;
        parentNode->right = node; // connect
        parentNode = node;
        flatten(left);
        flatten(right);
    }
};