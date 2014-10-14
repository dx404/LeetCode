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
        if (head == nullptr || head->next == nullptr ){
            return head;
        }
        ListNode *boss = new ListNode(head->val - 1);
        boss->next = head;
        
        ListNode *cur = boss;
        while (cur && cur->next && cur->next->next){
            if (cur->next->val == cur->next->next->val){
                ListNode *sCur = cur->next;
                while (sCur && sCur->val == cur->next->val){
                    sCur = sCur->next;
                }
                cur->next = sCur;
            }
            else
                cur = cur->next;
        }
        return boss->next;
    }
    
};