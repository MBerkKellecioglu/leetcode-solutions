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
private:
    int ans = 0;
public:
    int longestZigZag(TreeNode* root){

        dfs(root, 0, 0);
        dfs(root, 1, 0);

        return ans;
    }

    void dfs(TreeNode* root, bool direction, int path){

        if(!root){
            ans = max(ans, path - 1);
            return;
        }

        if(!direction){
            dfs(root->left, direction ^ 1, path + 1);
            dfs(root->right, direction, 1);
        }
        else{
            dfs(root->right, direction ^ 1, path + 1);
            dfs(root->left, direction, 1);
        }
    }
};