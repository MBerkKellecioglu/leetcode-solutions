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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        
        vector<int> curr;

        dfs(root, targetSum, curr, ans);

        return ans;
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& curr, vector<vector<int>>& ans){

        if(!root) return;

        targetSum -= root->val;

        curr.push_back(root->val);

        if(targetSum == 0 && !root->left && !root->right){
            ans.push_back(curr);
        }
        
        dfs(root->left, targetSum, curr, ans);
        dfs(root->right, targetSum, curr, ans);

        curr.pop_back();
    }
};