/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        deque <TreeNode*> cache;

        int level = 0;

        cache.push_front(root);

        while(!cache.empty()){
            int n = cache.size();

            if(level % 2 == 1){

                /* Level here is odd. What we are doing here is we are just swapping the odd level values and adding their childs
                   from left to right according to our binary tree(Thats why we are using stack for end half values at line 30)  */ 
                queue<TreeNode*> front_cache;
                stack<TreeNode*> end_cache;

                while(n > 0){
                    TreeNode* front = cache.front();
                    TreeNode* end = cache.back();

                    cache.pop_front();
                    cache.pop_back();

                    swap(front->val, end->val);

                    if(front->left) front_cache.push(front->left);
                    if(front->right) front_cache.push(front->right);

                    if(end->right) end_cache.push(end->right);
                    if(end->left) end_cache.push(end->left);

                    n -= 2;
                }

                while(!front_cache.empty()){
                    cache.push_back(front_cache.front());
                    front_cache.pop();
                }

                while(!end_cache.empty()){
                    cache.push_back(end_cache.top());
                    end_cache.pop();
                }
            }
            else{
                // This part is standart BFS logic. Level is even here.
                while(n > 0){
                    TreeNode* curr = cache.front();
                    cache.pop_front();

                    if(curr->left) cache.push_back(curr->left);
                    if(curr->right) cache.push_back(curr->right);

                    n--;
                }
            }
            
            level++;
        }

        return root;
    }
};