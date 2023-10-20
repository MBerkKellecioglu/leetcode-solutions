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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == 0) return NULL;

        vector<int> all_nums;
        ListNode* sol = new ListNode();
        ListNode* curr = sol;

        for(auto elements : lists){
            while(elements != NULL){
                all_nums.push_back(elements->val);
                elements = elements->next;
            }
        }
        sort(all_nums.begin(), all_nums.end());

        for(auto elements : all_nums){
            ListNode* new_node = new ListNode(elements);
            curr->next = new_node;
            curr = curr->next;
        }
        return sol->next;
    }
};