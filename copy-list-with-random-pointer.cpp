/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode *, RandomListNode *> toCopy; //old -> copy
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head==NULL) return NULL;
        RandomListNode *headCopy = new RandomListNode(head->label);
        toCopy[head] = headCopy;
        headCopy->next = copyRandomList(head->next);
        headCopy->random = toCopy[head->random];
        return headCopy;
    }
};