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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *r1, *r2, *head, *r3;
        r1 = l1;
        r2 = l2;
        head = NULL;
        while(r1 != NULL and r2 != NULL){
            if(r1->val <= r2->val){
                if(head == NULL){
                    head = r1;
                    r3 = head;
                    r1 = r1->next;
                }
                else{
                    r3->next = r1;
                    r3 = r3->next;
                    r1 = r1->next;
                }
            }
            else{
                if(head == NULL){
                    head = r2;
                    r3 = head;
                    r2 = r2->next;
                }
                else{
                    r3->next = r2;
                    r3 = r3->next;
                    r2 = r2->next;
                }
            }
        }
        if(r1==NULL){
            while(r2 != NULL){
                r3->next = r2;
                r3 = r3->next;
                r2 = r2->next;
            }
        }
        else if(r2==NULL){
            while(r1 != NULL){
                r3->next = r1;
                r3 = r3->next;
                r1 = r1->next;
            }
        }
        return head;
    }
};