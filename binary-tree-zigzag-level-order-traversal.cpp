/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define VI vector<int>
#define VII vector<VI >
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        VII result;
        if (root == nullptr)
            return result;
        deque<TreeNode *> cur;
        cur.push_back(root);
        bool leftToRight = true;
        while (!cur.empty()) {
            VI levelVal;
            deque<TreeNode *> next;
            while (!cur.empty()) {
                TreeNode *front = cur.front();
                levelVal.push_back(front->val);
                if (leftToRight) {
                    if (front->left)
                        next.push_front(front->left);
                    if (front->right)
                        next.push_front(front->right);
                }
                else {
                    if (front->right)
                        next.push_front(front->right);
                    if (front->left)
                        next.push_front(front->left);
                }
                cur.pop_front();
            }
            result.push_back(levelVal);
            cur = next;
            leftToRight = !leftToRight;
        }
        return result;
    }
};