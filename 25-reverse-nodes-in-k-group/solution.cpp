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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = head;
        ListNode* start = head;
        int k_count = 1, flag = 1;
        vector<pair<ListNode*, ListNode*>> all_heads;
        ListNode* tmp;

        while(end){
            if(k_count == k){
                tmp = end->next;
                end->next = NULL;
                start = reverseList(start);
                if(flag){
                    head = end;
                    flag = 0;
                }
                all_heads.push_back({end, start});
                end = tmp;
                start = tmp;
                k_count = 1;
            }
            if(end) end = end->next;
            else break;
            k_count++;
        }

        for(int i = 0; i < all_heads.size() - 1; i++) all_heads[i].second->next = all_heads[i + 1].first;
        
        all_heads[all_heads.size() - 1].second->next = tmp;

        return head;
    }


    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;

        ListNode *n = head->next; 
        ListNode *p = head;
        p->next = NULL;
        ListNode* new_end = head;

        while(n != NULL){
            head = n;
            n = head-> next;
            head->next = p;
            p = head;
        }
        return new_end;
    }
};