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
    TreeNode *fwd = nullptr, *fwd_cur = new TreeNode(numeric_limits<int>::min());
    TreeNode *bwd = nullptr, *bwd_cur = new TreeNode(numeric_limits<int>::max());
    void recoverTree(TreeNode *root) {
        inWalkFwd(root);
        inWalkBwd(root);
        swap(fwd->val, bwd->val);
    }
    
    void inWalkFwd(TreeNode *root){
        if (root == nullptr || fwd != nullptr)
            return;
        inWalkFwd(root->left);
        if (root->val < fwd_cur->val){
            fwd = fwd_cur;
            return;
        }
        fwd_cur = root;
        inWalkFwd(root->right);
    }
    
    void inWalkBwd(TreeNode *root){
        if (root == nullptr || bwd != nullptr)
            return;
        inWalkBwd(root->right);
        if (root->val > bwd_cur->val){
            bwd = bwd_cur;
            return;
        }
        bwd_cur = root;
        inWalkBwd(root->left);
    }
};