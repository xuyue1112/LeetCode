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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* cur = head;
        int length = 1;
        while(cur->next != NULL){
            cur = cur->next;
            length += 1;
        }
        if(length <= 1)
            return head;
        cur->next = head;
        int real_k = k % length;
        cur = head;
        int step = length - real_k;
        for(int i=0; i<step-1; i++){
            cur = cur->next;
        }
        ListNode* prev = cur;
        cur = cur->next;
        prev->next = NULL;
        return cur;
    }
};