
class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode *lessHead = NULL, *rightHead = NULL;
            ListNode *lessEnd = NULL, *rightEnd = NULL;
            while (head != NULL) {
                //cout << head << endl;
                if (head->val < x){
                    if(lessEnd == NULL){
                        lessHead = head;
                        lessEnd = head;
                    }
                    else{
                        lessEnd->next = head;
                        lessEnd = head;
                    }
                }
                else{
                    if(rightEnd == NULL){
                        rightHead = head;
                        rightEnd = head;
                    }
                    else{
                        rightEnd->next = head;
                        rightEnd = head;
                    }
                }
                head = head->next;
            }
            if (rightEnd!=NULL){
                rightEnd->next = NULL;
            }
            if (lessHead == NULL){

                return rightHead;
            }
            else{
                lessEnd->next = rightHead;
                return lessHead;
            }
        }
    
};