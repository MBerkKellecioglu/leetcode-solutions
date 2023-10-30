class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root) return false;

        return recSum(root, targetSum);
    }

    bool recSum(TreeNode* root, int target){
        target -= root->val;

        if(!root->left && !root->right) return (target == 0);

        bool l, r;

        if(root->left)  l = recSum(root->left, target);
        if(root->right) r = recSum(root->right, target);

        return l || r;
    }
};