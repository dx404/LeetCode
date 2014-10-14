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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n)
            return head;
        head = fwdWalk(head, m - 1);
        head = backWalk(head, n - m + 1);
        head = fwdWalk(head, INT_MAX);
        flush_link();
        return newHead;
    }
private:
    ListNode *Link_buffer[2];
    bool isBufferFull = false;
    int num = 0; //0 or 1
    ListNode *newHead;
    void push_link(ListNode *node){
        if (num == 0)
            newHead = node;
        Link_buffer[(num++) & 1] = node;
        isBufferFull = isBufferFull || (num > 1);
        if (isBufferFull){
            Link_buffer[num & 1]->next = node;
        }
    }
    
    void flush_link(){
        if (isBufferFull){
            Link_buffer[num & 1]->next = Link_buffer[(num-1) & 1];
            Link_buffer[(num-1) & 1]->next = NULL;
        }
    }
    
    ListNode *fwdWalk(ListNode *head, int steps){
        if (steps == 0 || head == NULL){
            return head;
        }
        push_link(head);
        return fwdWalk(head->next, steps-1);
    }
    
    ListNode *backWalk(ListNode *head, int steps){
        if (steps == 0 || head == NULL ){
            return head;
        }
        ListNode *node = backWalk(head->next, steps-1);
        push_link(head);
        return node ;
    }
};