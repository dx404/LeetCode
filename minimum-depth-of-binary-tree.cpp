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
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int dl = (root->left == NULL) ? INT_MAX : minDepth(root->left);
        int dr = (root->right == NULL) ? INT_MAX : minDepth(root->right);
        return 1 + min(dl, dr);
    }
};