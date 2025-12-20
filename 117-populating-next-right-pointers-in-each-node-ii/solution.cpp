/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return nullptr;
        
        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            Node* prev = nullptr;

            while(sz > 0){
                Node* next = q.front();

                if(prev) prev->next = next;
                prev = next;

                q.pop();
                
                if(next->left) q.push(next->left);
                if(next->right) q.push(next->right);
                
                sz--;
            }
        }

        return root;
    }
};