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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int max_depth = 0;

        TreeNode* ans = nullptr;

        postOrder(root, ans, max_depth, 0);

        return ans;
    }

    int postOrder(TreeNode* root, TreeNode*&ans, int& max_depth, int depth){

        if(!root) return -1;

        if(!root->left && !root->right){
            if(depth >= max_depth){
                max_depth = depth;
                ans = root;
                return depth;
            }
        }

        int l = postOrder(root->left, ans, max_depth, depth + 1);
        int r = postOrder(root->right, ans, max_depth, depth + 1);

        if(l == r && l == max_depth) ans = root;

        return max(l, r);
    }
};