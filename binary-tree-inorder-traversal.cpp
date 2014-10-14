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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<pair<TreeNode*, int> > trace ({{root, 0}}); //initialization
        while(!trace.empty()) {
            TreeNode *cur = trace.top().first;
            int &status = trace.top().second;
            if (status == 0) {
                if (cur->left) trace.push({cur->left, 0});
            }
            else if (status == 1) {
                result.push_back(cur->val);
                if (cur->right) trace.push({cur->right, 0});
            }
            else if (status == 2) {
                trace.pop();
            }
            status++;
        }
        return result;
    }
};