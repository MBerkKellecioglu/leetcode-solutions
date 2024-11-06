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
    void flatten(TreeNode* root) {
        
        dfs(root);
    }

    void dfs(TreeNode*& root){
        if(!root) return;

        dfs(root->left);
        dfs(root->right);

        TreeNode* r = root->right;
        TreeNode* l = root->left;

        if(!l) return;
        else if(l && !r){
            root->left = nullptr;
            root->right = l;
        }
        else{
            root->left = nullptr;
            root->right = nullptr;

            root->right = l;
            
            while(l->right) l = l->right;

            l->right = r;
        }

        return;
    }
};