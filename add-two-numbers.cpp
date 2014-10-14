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
    ListNode *toNext(ListNode *v){
        return (v == NULL) ? NULL : v->next;
    }
    int getVal(ListNode *v){
        return (v == NULL) ? 0 : v->val;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if (l1 == NULL && l2 == NULL){
            return (carry == 0) ? NULL : new ListNode(carry);
        }
        int sum = getVal(l1) + getVal(l2) + carry;
        ListNode *l3 = new ListNode(sum % 10);
        l3->next = addTwoNumbers(toNext(l1), toNext(l2), sum / 10);
        return l3;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers(l1, l2, 0);
    }
};