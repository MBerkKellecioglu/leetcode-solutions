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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        queue<TreeNode*> cache;

        vector<vector<int>> sol;

        int flag = 0;

        cache.push(root);
        
        while(!cache.empty()){
            int sz = cache.size();
            vector<int> levels;

            while(sz > 0){
                TreeNode* tmp = cache.front();
                cache.pop();
                levels.push_back(tmp->val);
                if(tmp->left != nullptr) cache.push(tmp->left);
                if(tmp->right != nullptr) cache.push(tmp->right);
                sz--;
            }
            if(flag){
                reverse(levels.begin(), levels.end());
                flag--; 
            }
            else flag++;

            sol.push_back(levels);
        }

        return sol;   
    }
};