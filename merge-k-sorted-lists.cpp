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
    ListNode *postNext(ListNode* &node){
        ListNode *old = node;
        node = node->next;
        return old;
    }
    static bool comp(ListNode *n1, ListNode *n2){
        if (n1 == NULL) return false;
        if (n2 == NULL) return true;
        return n1->val < n2->val;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = (int) lists.size();
        if (k == 0){
            return NULL;
        }
        ListNode **minEle = min_element(&lists[0], &lists[k], comp);
        if (*minEle == NULL){
            return NULL;
        }
        ListNode *head = postNext(*minEle);
        head->next = mergeKLists(lists);
        return head;
    }
};