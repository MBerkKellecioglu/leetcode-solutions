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
    ListNode* deleteDuplicates(ListNode* head){

        if(!head) return nullptr;
        
        // prev will hold the number that is before our current number
        ListNode* curr = head;
        ListNode* prev = head;

        bool flag = false;

        while(curr != nullptr){
            //  this is for checking whether our curr number is dup if it is we stop at the last dup number // 
            while(curr->next && curr->val == curr->next->val){
                flag = 1;
                curr = curr->next;
            }

            if(flag){
                /* first if statement is for an edge case where we might
                   have a dup number as head of the linked list*/
                if(curr->val == head->val){
                    prev = curr->next;
                    curr->next = nullptr;
                    curr = prev;
                    head = curr;
                }
                /* pretty simple we connect prev number with our curr dup numbers NEXT number
                   so if its like (2, 3, 3, 3, 4) we connect 2 and 4 (prev = 2 and curr->NEXT = 4) */
                else{
                    prev->next = curr->next;
                    curr->next = nullptr;
                    curr = prev->next;
                }

                flag = 0;
            }
            else{
                // if our curr num is not dup we just iterate //
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }


};