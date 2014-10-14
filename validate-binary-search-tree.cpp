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
    int val = INT_MIN;
    bool update(int val){
        if (this->val < val){
            this->val = val;
            return true;
        }
        return false;
    }
    
    bool isValidBST(TreeNode *root) {
        return root == NULL ||
            isValidBST(root->left) && 
            update(root->val) &&
            isValidBST(root->right);
    }
};