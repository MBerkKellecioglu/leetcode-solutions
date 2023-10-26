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
    int diameterOfBinaryTree(TreeNode* root){
        vector<int> sol = RecDiameter(root);
        return sol[1];
    }

    vector<int> RecDiameter(TreeNode* root){
        if(root == NULL) return {0,0};

        vector<int> ld = RecDiameter(root->left);
        vector<int> rd = RecDiameter(root->right);

        

        return {max(ld[0], rd[0]) + 1, max({ld[0] + rd[0], ld[1], rd[1]})};
    }
};