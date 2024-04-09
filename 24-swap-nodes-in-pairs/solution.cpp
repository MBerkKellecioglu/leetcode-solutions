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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL) return NULL;
        else if(head->next == NULL) return head;

        ListNode* prev_p = NULL;
        ListNode* p1 = head;
        ListNode* p2 = head->next;

        head = p2;

        while(p2 != NULL){
            ListNode* next_p = p2->next;

            p2->next = p1;
            p1->next = next_p;

            if(prev_p != NULL) prev_p->next = p2;

            prev_p = p1;
            p1 = next_p;
            if(next_p != NULL) p2 = next_p->next;
            else break;
        }

        return head;
    }
};