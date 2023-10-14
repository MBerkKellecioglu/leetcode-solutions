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
    void reorderList(ListNode* list){
        stack<int> st;
        ListNode *tmp = list;
        int list_size = 0, flag = 0;

        while(tmp != NULL){
            st.push(tmp->val);
            tmp = tmp->next;
            list_size++;
        }
        if(list_size % 2 == 1) flag = 1;
        tmp = list;
        list_size--;
        list_size /= 2;

        while(list_size > 0){
            ListNode *new_node = new ListNode(st.top());
            new_node->next = tmp->next;
            tmp->next = new_node;
            tmp = tmp->next->next;
            list_size--;
            st.pop();
        }
        
        if(flag == 1) tmp->next = NULL;
        else tmp->next->next = NULL;
    }
};