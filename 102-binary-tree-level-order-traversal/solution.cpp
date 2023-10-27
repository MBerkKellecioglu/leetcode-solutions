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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> sol;
        if(root == NULL) return sol;
        deque<TreeNode*> cache;

        cache.push_back(root);

        while(!cache.empty()){
            vector<int> sub_sol;
            int q_size = cache.size();

            for(int i = 0; i < q_size; i++){
                TreeNode* tmp = cache.front();
                cache.pop_front();
                sub_sol.push_back(tmp->val);
                if(tmp->left) cache.push_back(tmp->left);
                if(tmp->right) cache.push_back(tmp->right);
            }
            sol.push_back(sub_sol);
        }

        return sol;
    }
};