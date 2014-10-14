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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        stack<pair<TreeNode*, int> > trace;
        trace.push({root, 0});
        while (!trace.empty()) {
            TreeNode *node = trace.top().first;
            int &stage = trace.top().second;
            if (stage == 0) {
                if (node->left) trace.push({node->left, 0});
            }
            else if (stage == 1) {
                if (node->right) trace.push({node->right, 0});
            }
            else {
                result.push_back(node->val);
                trace.pop();
            }
            stage++;
        }
        return result;
    }
};