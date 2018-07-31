class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* pTmp = head;
        while(pTmp != NULL){
            length += 1;
            pTmp = pTmp->next;
        }
        pTmp = head;
        if(length-n-1 < 0)
            return head->next;
        for(int i = 0; i<length-n-1; i++){
            pTmp = pTmp->next;
        }
        pTmp->next = pTmp->next->next;
        return head;
    }
};
