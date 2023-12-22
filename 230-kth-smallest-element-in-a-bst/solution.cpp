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
    int kthSmallest(TreeNode* root, int k){
        return recSmallest(root, k);
    }

    int recSmallest(TreeNode* root, int &k){
        if(root == NULL) return 0;

        int sol = recSmallest(root->left, k);

        k--;

        if(k == 0) sol = root->val;
        if(k <= 0) return sol;

        sol = recSmallest(root->right, k);

        return sol;
    }
};