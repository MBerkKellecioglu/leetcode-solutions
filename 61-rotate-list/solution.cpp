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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr) return nullptr;
        
        ListNode* curr = head;

        int count = 1;

        while(curr->next != nullptr){
            curr = curr->next;
            count++;
        }

        if(count == 1) return head;

        k %= count;

        while(k > 0){
            head = rotate(head);
            k--;
        }

        return head;
    }

    ListNode* rotate(ListNode* head){
        
        ListNode* penultimate = head;

        while(penultimate->next->next != nullptr){
            penultimate = penultimate->next;
        }

        ListNode* last = penultimate->next;

        penultimate->next = nullptr;
        last->next = head;
        head = last;

        return head;
    }
};