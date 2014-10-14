/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *a = head;
        ListNode *b = a->next;
        while (a != NULL){
            while (b != NULL && a->val == b->val){
                b = b->next;
            }
            a->next = b;
            a = a->next;
        }
        return head;
    }
};