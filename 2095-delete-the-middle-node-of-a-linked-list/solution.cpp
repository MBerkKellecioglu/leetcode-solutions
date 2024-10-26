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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == nullptr) return nullptr;
        
        ListNode* f = head;
        ListNode* s = new ListNode(0, head);

        while(f->next != nullptr){
            f = f->next;
            if(f->next != nullptr) f = f->next;
            s = s->next;
        }

        ListNode* mid = s->next;

        f = s->next->next;

        s->next = nullptr;
        mid->next = nullptr;
        s->next = f;
        
        return head;
    }
};