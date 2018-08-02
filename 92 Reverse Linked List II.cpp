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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        ListNode* cur = head;
        int curIndex = 1;
        while(curIndex < m-1){
            cur = cur->next;
            curIndex += 1;
        }
        ListNode *p1, *p2, *p3, *tmp;
        int flag = 0;
        if(curIndex > m-1){
            flag = -1;
            p1 = (ListNode*)malloc(sizeof(ListNode));
            p1->val = -1;
            p1->next = cur;
            p2 = cur;
            p3 = p2->next;
            tmp = NULL;
        }
        else{
            p1 = cur;
            cur = cur->next;
            curIndex += 1;
            p2 = cur;
            p3 = p2->next;
            tmp = NULL;
        }
        while(curIndex < n){
            p2->next = tmp;
            tmp = p2;
            p2 = p3;
            p3 = p3->next;
            curIndex += 1;
        }
        p2->next = tmp;
        
        p1->next->next = p3;
        p1->next = p2;
        if(flag == -1){
            head = p2;
        }
        return head;
    }
        
};