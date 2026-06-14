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
    int pairSum(ListNode* head) {
        
        ListNode* fh = new ListNode(0, head);
        ListNode* sh = head;

        int h = 0, ans = 0;

        while(sh != nullptr){
            fh = fh->next;
            sh = sh->next->next;
            h++;
        }

        sh = fh->next;

        fh->next = nullptr;
        fh = head;

        reverse(sh, h);
        
        while(fh != nullptr){
            ans = max(ans, fh->val + sh->val);
            fh = fh->next;
            sh = sh->next;
        }

        return ans;
    }

    void reverse(ListNode*& head, int& h){
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(h > 0){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) next = next->next;
            h--;
        }

        head = prev;
    }
};