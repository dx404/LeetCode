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
 	ListNode *reverseKGroup(ListNode *head, int k) {
 		if (head == nullptr || head->next == nullptr || k <= 1)
 			return head;
 		ListNode *next_group = head;
 		for (int i = 0; i < k; ++i) {
 			if (next_group)
 				next_group = next_group->next;
 			else
 				return head;
 		}
        // next_group is the head of next group
        // new_next_group is the new head of next group after reversion
 		ListNode *new_next_group = reverseKGroup(next_group, k);
 		ListNode *prev = nullptr, *cur = head;
 		while (cur != next_group) {
 			ListNode *next = cur->next;
 			cur->next = prev ? prev : new_next_group;
 			prev = cur;
 			cur = next;
 		}
		return prev; // prev will be the new head of this group
	}
};