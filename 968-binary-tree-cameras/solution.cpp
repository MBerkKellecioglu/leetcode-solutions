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
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;

        int sum = 0;
        
        if(!recCamera(root, sum)) sum++;

        return sum;
    }

    int recCamera(TreeNode* root, int& sum){
        if(!root) return 1;

        int l = recCamera(root->left, sum);
        int r = recCamera(root->right, sum);

        if(!l || !r){
            sum++;
            return 2;
        }

        if(l == 2 || r == 2) return 1;

        return 0;
    }
};