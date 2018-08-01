class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t1;
        ListNode *t2;
        t1 = t2 = head;
        while(t2 != NULL){
            while(t2->val == t1->val){
                t2 = t2->next;
                if(t2==NULL)
                    break;
            }
            t1->next = t2;
            t1 = t2;
        }
        return head;
    }
};