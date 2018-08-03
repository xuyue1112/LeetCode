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
    void reorderList(ListNode* head) {
        ListNode *cur = head;
        int length = 0;
        while(cur != NULL){
            cur = cur->next;
            length += 1;
        }
        if(length<=1)
            return;
        cout << length << endl;
        int startIndex = (length+1) / 2;
        cur = head;
        for(int i=0; i<startIndex-1; i++){
            cur = cur->next;
        }
        ListNode * head2 = cur->next;
        cur->next = NULL;   
        ListNode *p0 = head2;
        ListNode *p1 = head2->next;
        ListNode *p2 = p1;
        head2->next = NULL;
        while(p2 != NULL){
            p2 = p2->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }
        head2 = p0;
        // 现在head 和 head2是两个列表的头
        cur = head;
        ListNode *cur2;
        ListNode *cur2_next;
        cur2 = head2;
        cur2_next = cur2;
        while(cur2!=NULL){
            cur2_next = cur2->next;
            cur2->next = cur->next;
            cur->next = cur2;
            cur = cur2->next;
            cur2 = cur2_next;
        }
    }
};