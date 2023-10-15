/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){
        if(head == NULL) return NULL;
        
        unordered_map<Node*, Node*> adress;
        Node *org_curr = head->next;
        Node* copy = new Node(head->val);
        Node* cpy_curr = copy;

        adress[head] = cpy_curr;

        while(org_curr != NULL){
            Node* new_node = new Node(org_curr->val);
            adress[org_curr] = new_node;
            cpy_curr->next = new_node;
            cpy_curr = cpy_curr->next;
            org_curr = org_curr->next;
        }

        org_curr = head;
        cpy_curr = copy;

        while(org_curr != NULL){
            cpy_curr->random = adress[org_curr->random];
            org_curr = org_curr->next;
            cpy_curr = cpy_curr->next;
        }

        return copy;
    }
};