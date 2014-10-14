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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> cur;
        cur.push(root);
        while (!cur.empty()) {
            queue<TreeNode *> next;
            vector<int> levelVal;
            while (!cur.empty()) {
                TreeNode *front = cur.front();
                levelVal.push_back(front->val);
                if (front->left) 
                    next.push(front->left);
                if (front->right)
                    next.push(front->right);
                cur.pop();
            }
            result.push_back(levelVal);
            cur = next;
        }
        return result;
    }
};