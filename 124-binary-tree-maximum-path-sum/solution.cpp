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
    int maxPathSum(TreeNode* root) {
        int sol = INT_MIN;
        recPath(root, sol);
        return sol;
    }

    int recPath(TreeNode* root, int &sol){
        if(root == NULL) return -10001;

        int l = recPath(root->left, sol);
        int r = recPath(root->right, sol);

        int sub_tree_max = l + r + root->val;
        int path_max = max(max(l, r) + root->val, root->val);

        sol = max({path_max, sub_tree_max,sol});

        return path_max;
    }
};