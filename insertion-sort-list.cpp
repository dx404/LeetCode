/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *dummyHead = new ListNode(numeric_limits<int>::min());
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        return insertToSortList(head, insertionSortList(head->next));
        
    }
    ListNode *insertToSortList(ListNode *node, ListNode *head){
        dummyHead->next = head;
        ListNode *pre = dummyHead, *cur = head;
        while (cur != nullptr && node->val > cur->val){
            pre = cur;
            cur = cur->next;
        }
        node->next = cur;
        pre->next = node;
        return dummyHead->next;
    }
    
};