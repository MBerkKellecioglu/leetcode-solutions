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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* merged = new ListNode();
        ListNode* curr = merged;

        while(l1 != NULL || l2 != NULL){
            int num1 = (l1 != NULL) ? l1->val : INT_MAX;
            int num2 = (l2 != NULL) ? l2->val : INT_MAX;
            ListNode* new_node = new ListNode();
            
            if(num1 > num2){
                new_node->val = num2;
                l2 = l2->next;
            }
            else if(num1 < num2){
                new_node->val = num1;
                l1 = l1->next;
            }
            else{
                ListNode* new_node2 = new ListNode(num2);
                new_node->val = num1;
                l1 = l1->next;
                l2 = l2->next;
                curr = addNodes(curr, new_node2);
            }
            curr = addNodes(curr, new_node);
        }   
        return merged->next;
    }
    ListNode* addNodes(ListNode* lst, ListNode* node){
        lst->next = node;
        return lst->next;
    }
};