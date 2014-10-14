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
    vector<vector<int> > result;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        dfs(root, sum, vector<int>());
        return result;
    }
    
    void dfs(TreeNode *node, int sum, vector<int> trace) {
        if (node == nullptr)
            return;
        trace.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == sum)
                result.push_back(trace);
            return;
        }
        dfs(node->left, sum - node->val, trace);
        dfs(node->right, sum - node->val, trace);
    }
};