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
    vector<int> rightSideView(TreeNode* root){

        if(!root) return {};

        queue<TreeNode*> cache;

        vector<int> ans;

        TreeNode* curr;

        cache.push(root);

        while(!cache.empty()){
            int n = cache.size();

            while(n > 1){
                curr = cache.front();

                if(curr->left) cache.push(curr->left);
                if(curr->right) cache.push(curr->right);

                cache.pop();
                n--;
            }

            curr = cache.front();

            ans.push_back(curr->val);

            if(curr->left) cache.push(curr->left);
            if(curr->right) cache.push(curr->right);

            cache.pop();
        }

        return ans;
    }

};