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
    ListNode* reverseBetween(ListNode* head, int left, int right){

        if(head->next == nullptr || left - right == 0) return head;

        ListNode* right_boundry = head;
        ListNode* left_boundry = head;

        int flag = 0, i = 1;

        vector<int> reversed;

        while(i < right + 1){
            if(i == left){
                flag = 1;
                left_boundry = right_boundry;
            }

            i++;
            if(flag) reversed.push_back(right_boundry->val);

            right_boundry = right_boundry->next;
        }

        reverse(reversed.begin(), reversed.end());

        i = 0;

        while(i  < right - left + 1){
            left_boundry->val = reversed[i];
            i++;
            left_boundry = left_boundry->next;
        }

        return head;
        
    }
};