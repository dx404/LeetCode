/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class MySafeStack : public stack<pair<TreeNode*, int> > {
public:
    void guard_push(pair<TreeNode*, int> pairData) {
        if (pairData.first)
            this->push(pairData);
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) return result;
        MySafeStack trace;
        trace.guard_push({root, 0});
        while (!trace.empty()) {
            TreeNode *cur = trace.top().first;
            int &stage = trace.top().second;
            if (stage == 0) {
                result.push_back(cur->val);
                trace.guard_push({cur->left, 0});
            }
            else if (stage == 1) {
                trace.guard_push({cur->right, 0});
            }
            else {
                trace.pop();
            }
            stage++;
        }
        return result;
    }
};