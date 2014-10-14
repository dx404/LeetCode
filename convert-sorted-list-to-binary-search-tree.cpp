/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode *lslow = head, *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            lslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        lslow->next = NULL;
        TreeNode *left = sortedListToBST(head);
        TreeNode *right = sortedListToBST(slow->next);
        TreeNode *root = new TreeNode(slow->val);
        root->left = left;
        root->right = right;
        return root;
    }
};
