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
    ListNode* partition(ListNode* head, int x){
        ListNode* curr = head;

        ListNode* low = new ListNode();
        ListNode* low_curr = low;

        ListNode* high = new ListNode();
        ListNode* high_curr = high;

        while(curr != NULL){
            if(curr->val < x){
                low_curr->next = new ListNode(curr->val);
                low_curr = low_curr->next;
            }
            else{
                high_curr->next = new ListNode(curr->val);
                high_curr = high_curr->next;
            }
            curr = curr->next;
        }

        high = high->next;

        low_curr->next = high;

        return low->next;
    }
};