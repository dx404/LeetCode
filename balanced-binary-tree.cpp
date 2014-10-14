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
    map<TreeNode*, int> h;
    int getHeight (TreeNode *node) {
        if (node == NULL){
            return h[node] = -1;
        }
        if (node->left == NULL && node->right == NULL){
            return 0;
        }
        if (h.count(node) > 0){
            return h[node];
        }
        return h[node] = 1 + max(getHeight(node->left), getHeight(node->right));
        
    }
    
    bool isBalanced(TreeNode *root) {
        getHeight(root);
        if (root == NULL){
            return -1;
        }
        if (root->left == NULL && root->right == NULL){
            return true;
        }
        return 
            isBalanced(root->left) && 
            isBalanced(root->right) && 
            h[root->left] - h[root->right] >= -1 && 
            h[root->left] - h[root->right] <= 1;
    }
};