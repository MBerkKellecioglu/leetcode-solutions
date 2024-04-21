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
    int findBottomLeftValue(TreeNode* root){

        int max_depth = 0;

        pair<int, int> sol = {0, 0}; // first is value, second is depth 

        inorder(root, 0, sol);

        return sol.first;
    }

    void inorder(TreeNode* root, int depth, pair<int, int>& sol){
        
        if(!root) return;

        if(sol.second < depth || sol.second == 0){
            sol.first = root->val;
            sol.second = depth;
        }

        inorder(root->left, depth + 1, sol);
        inorder(root->right, depth + 1, sol);
    }
};