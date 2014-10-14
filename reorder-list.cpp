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
    void reorderList(ListNode *head) {
        if (head == NULL|| head->next == NULL)
            	return;
        ListNode * p1 = head;
        ListNode * p2 = head->next;
        dfs(NULL, head, p1, p2);
    }

    void dfs(ListNode * candi_pre, ListNode * candi, ListNode* & p1, ListNode*& p2) {
        if (candi->next)
             dfs(candi, candi->next, p1, p2);
    
        if (p2 == NULL || p2->next == NULL)
            	return;

        candi_pre->next = NULL;
        p1->next = candi;
        candi->next = p2;
        p1 = p2;
        p2 = p2->next;
    }    
};
