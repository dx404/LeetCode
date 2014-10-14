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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        int n = 0;
        ListNode *end = head;
        while (end->next != NULL){
            end = end->next;
            n++;
        }
        int k_mod = k % (n+1);
        k_mod = (n+1-k_mod) %(n+1); // firstly got the wrong rotation direction
        if (k_mod == 0){
            return head;
        }
        ListNode *pre = nullptr, *newHead = head;
        for (int i = 0; i < k_mod; i++){
            pre = newHead;
            newHead = newHead->next;
        }
        pre->next = nullptr;
        end->next = head;
        return newHead;
    }
};