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
    bool isBalanced(TreeNode* root){
        int sol = recBalance(root);

        if(sol == -1) return false;

        return true;
    }

    int recBalance(TreeNode* root){
        if(root == NULL) return 0;

        int left = recBalance(root->left);
        int right = recBalance(root->right);

        if( (left == -1 || right == -1) || (abs(left - right) > 1) ) return -1;

        return max(left, right) + 1;
    }
};