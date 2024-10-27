/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;

        ListNode *n = head->next; 
        ListNode *p = head;
        p->next = NULL;

        while(n != NULL){
            head = n;
            n = head-> next;
            head->next = p;
            p = head;
        }
        return head;
    }
};