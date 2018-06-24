class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        int length = 1;
        ListNode * tail = head;
        while(tail->next != NULL){
            length += 1;
            tail = tail->next;
        }
        ListNode * middle = head;
        
        for(int i=0; i<length/2; i++){
            middle = middle->next;
        }
        //别忘了考虑临界情况:链表特别短
        int count = 0;
        ListNode * pointers[3];
        pointers[0] = middle;
        pointers[1] = middle->next;
        pointers[2] = middle->next->next;
        while(pointers[(count+2) % 3 ] != NULL){
            pointers[(count+1)%3]->next = pointers[(count+0)%3];
            pointers[(count+0)%3] = pointers[(count+2)%3]->next;
            if(pointers[(count+0)%3] == NULL){
                pointers[(count+2)%3]->next = pointers[(count+1)%3];
                break;
            }
        }
        for(int i=0; i<length/2-1; i++){
            if(head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
        
    }
};