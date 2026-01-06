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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> cache;

        int n = 0, ans = 0, sum = 0, level = 1, max_sum = INT_MIN;

        TreeNode* curr;

        cache.push(root);

        while(!cache.empty()){
            n = cache.size();
            sum = 0;

            while(n > 0){
                curr = cache.front();
                sum += curr->val;
                if(curr->left) cache.push(curr->left);
                if(curr->right) cache.push(curr->right);
                n--;
                cache.pop();
            }

            if(sum > max_sum){
                ans = level;
                max_sum = sum;
            }

            level++; 
        }

        return ans;
    }
};