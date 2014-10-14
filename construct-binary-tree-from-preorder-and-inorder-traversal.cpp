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
    map<int, int> inorderIndex;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = (int) inorder.size();
        for(int i = 0; i < n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return treeItFromPre(preorder, 0, 0, n);
    }
    
    TreeNode *treeItFromPre(vector<int> &preorder, int preStart, int inStart, int len){
        if (len <= 0)
            return nullptr;
        int leftLen = inorderIndex[preorder[preStart]] - inStart;
        TreeNode *root = new TreeNode(preorder[preStart]);
        root->left = treeItFromPre(preorder, preStart + 1, inStart, leftLen);
        root->right = treeItFromPre(preorder, preStart + leftLen + 1, inStart + leftLen + 1, len - leftLen - 1);
        return root;
    }
};