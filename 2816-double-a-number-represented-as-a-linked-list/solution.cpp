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
    ListNode* doubleIt(ListNode* head) {
        
        int carry = dfs(head);

        if(carry != 0){
            ListNode* n_head = new ListNode();
            n_head->val = carry;

            n_head->next = head;

            head = n_head;
        }

        return head;
    }

    int dfs(ListNode* head){
        
        if(!head) return 0;

        int carry = dfs(head->next);

        head->val = ((head->val * 2) + carry);

        carry = head->val / 10;

        head->val %= 10;

        return carry;
    }
};