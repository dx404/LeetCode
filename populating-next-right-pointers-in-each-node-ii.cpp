/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        TreeLinkNode *nextHeadparent = new TreeLinkNode(-1);
        for(TreeLinkNode *rowHead = root; rowHead; rowHead = nextHeadparent->next) {
            nextHeadparent->next = nullptr;
            TreeLinkNode *lastCur = nextHeadparent;
            for (TreeLinkNode *cur = rowHead; cur; cur = cur->next){
                if (cur->left) {
                    lastCur->next = cur->left;
                    lastCur = cur->left;
                }
                if (cur->right) {
                    lastCur->next = cur->right;
                    lastCur = cur->right;
                }
            }
        }
        delete nextHeadparent;
    }
};