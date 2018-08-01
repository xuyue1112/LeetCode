class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        return reverseList(head, head->next);     
    }
    ListNode* reverseList(ListNode* h1, ListNode* h2){
        if(h2==NULL){
            return h1;
        }
        else
            h2 = reverseList(h2, h2->next);
        ListNode* tail2 = h2;
        while(tail2->next != NULL){
            tail2 = tail2->next;
        }
        tail2->next = h1;
        h1->next = NULL;
        return h2;
    }
};