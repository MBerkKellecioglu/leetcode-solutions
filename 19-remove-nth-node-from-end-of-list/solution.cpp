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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *left = head;
        ListNode *right = head;
        int count = 1;

        while(right->next != NULL){
            right = right->next;
            count++;
        }

        if(count == n){
            head = head->next;
            return head;
        }

        count -= (n + 1);

        while(count > 0){
            left = left->next;
            count--;
        }

        left->next = left->next->next;
        return head;
    }
};