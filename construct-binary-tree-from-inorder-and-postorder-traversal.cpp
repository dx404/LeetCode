/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
  1
 / \ 
3   2
    inorder 3, 1, 2
    preorder 1, 3, 2
 */
 
class Solution {
public:
    map<int, int> inorderIndex;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = (int) inorder.size();
        for(int i = 0; i < n; i++){
            inorderIndex[inorder[i]] = i;
        }
        return treeItFromPost(postorder, 0, 0, n);
    }

    TreeNode *treeItFromPost(vector<int> &postorder, int postStart, int inStart, int len){
        if (len <= 0)
            return nullptr;
        int leftLen = inorderIndex[postorder[postStart + len - 1]] - inStart;
        TreeNode *root = new TreeNode(postorder[postStart + len - 1]);
        root->left = treeItFromPost(postorder, postStart, inStart, leftLen);
        root->right = treeItFromPost(postorder, postStart + leftLen, inStart + leftLen + 1, len - leftLen - 1);
        return root;
    }
};