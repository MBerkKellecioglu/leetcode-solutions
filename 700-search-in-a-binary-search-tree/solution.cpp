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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* sol = nullptr;

        dfs(root, sol, val);

        return sol;
    }

    void dfs(TreeNode* root, TreeNode*& sol, int& val){

        if(root == nullptr) return;

        if(root->val == val){
            sol = root;
            return;
        }
        
        if(root->val < val){
            dfs(root->right, sol, val);
        }
        else dfs(root->left, sol, val);
    }
};