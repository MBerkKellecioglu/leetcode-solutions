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
using ll = long long;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        
        queue<TreeNode*> q;

        ll sum = 0, MOD = pow(10,9) + 7, ans = LLONG_MIN;

        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            sum += curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        dfs(root, sum, ans);

        return ans % MOD;
    }

    ll dfs(TreeNode* root, ll& sum, ll& ans){
        
        if(!root) return 0;

        ll sub_sum = root->val;

        sub_sum += dfs(root->left, sum, ans);
        sub_sum += dfs(root->right, sum, ans);

        ans = max(ans, (sub_sum * (sum - sub_sum)));

        return sub_sum;
    }
};