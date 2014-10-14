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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fake = new ListNode(-1);
        vector<ListNode *> bf(n + 1, fake);
        ListNode *node = head;
        int i = 0; 
        while(node != NULL){          
            bf[i % (n+1)] = node;
            node = node -> next;
            i++;
        } 
        ListNode *pre = bf[i % (n+1)];
        if (pre == fake)
            head = head->next;
        else
            pre->next = pre->next->next;
        delete fake;
        return head;
    }
};