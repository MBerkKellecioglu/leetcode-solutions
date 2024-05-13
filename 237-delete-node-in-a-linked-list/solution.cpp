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
    void deleteNode(ListNode* n){

        traverse(n, NULL);

    }

    void traverse(ListNode* n, ListNode* pre_n){

        if(n->next == NULL){
            pre_n->next = NULL;

            return;
        }

        n->val = n->next->val;

        traverse(n->next, n);
    }
};