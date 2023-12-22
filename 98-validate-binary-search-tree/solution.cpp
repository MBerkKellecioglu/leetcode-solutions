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
    bool isValidBST(TreeNode* root){
        vector<int> sol;
        recValid(root, sol);
        set<int> valid(sol.begin(), sol.end());
        vector<int> sol2(valid.begin(), valid.end());

        if(sol != sol2) return false;

        return true;
    }

    void recValid(TreeNode* root, vector<int>& all_values){
        if(root == NULL) return;

        recValid(root->left, all_values);

        all_values.push_back(root->val);

        recValid(root->right, all_values);
    }
};