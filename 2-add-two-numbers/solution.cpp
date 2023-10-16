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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int sum = 0, carry = 0;
        ListNode* sol = new ListNode();
        ListNode* curr = sol;

        while(l1 != NULL && l2 != NULL){
            sum = (l1->val) + (l2->val) + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *new_node = new ListNode(sum);
            curr->next = new_node;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != NULL){
            while(l1 != NULL){
                sum = (l1->val) + carry;
                carry = sum / 10;
                sum %= 10;
                ListNode *new_node = new ListNode(sum);
                curr->next = new_node;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        else if(l2 != NULL){
            while(l2 != NULL){
                sum = (l2->val) + carry;
                carry = sum / 10;
                sum %= 10;
                ListNode *new_node = new ListNode(sum);
                curr->next = new_node;
                curr = curr->next;
                l2 = l2->next;
            }  
        }
        if(carry == 1){
            ListNode *new_node = new ListNode(1);
            curr->next = new_node;
        }
        
        return sol->next;
    }
};