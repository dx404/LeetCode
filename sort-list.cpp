class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rightSorted = sortList(slow->next);
        slow->next = nullptr;
        ListNode *leftSorted = sortList(head);
        return mergeList(leftSorted, rightSorted);
    }
    
    ListNode *mergeList(ListNode *left, ListNode *right){
        if (left == nullptr)
            return mergeList(right, left);
        if (right != nullptr && left->val > right->val)
            return mergeList(right, left);
        ListNode *curMerge = left;
        ListNode *curLeft = left->next, *curRight = right;
        while (curLeft && curRight){
            if (curLeft->val < curRight->val){
                curMerge->next = curLeft;
                curLeft = curLeft->next;
            }
            else {
                curMerge->next = curRight;
                curRight = curRight->next;
            }
            curMerge = curMerge->next;
        }
        
        if (curLeft){
            curMerge->next = curLeft;
        }
        if (curRight){
            curMerge->next = curRight;
        }
        return left;
    }
};