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
    TreeNode *sortedArrayToBST(vector<int> &num, int a, int b) {
        if (a > b) 
            return NULL;
        if (a == b) 
            return new TreeNode(num[a]);
        
        int m = (a+b)/2;
        TreeNode *mid = new TreeNode(num[m]);
        mid -> left = sortedArrayToBST(num, a, m-1);
        mid -> right = sortedArrayToBST(num, m+1, b);
        return mid;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
};