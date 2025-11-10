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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {


        vector<int> del(pow(10, 5) + 1, 0);

        for(int& n : nums){
            del[n] = 1;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            if(del[curr->val] == 1){
                ListNode* next = curr->next;
                
                if(prev){
                    prev->next = nullptr;
                    prev->next = next;
                }
                else head = next;

                curr->next = nullptr;
                curr = next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};