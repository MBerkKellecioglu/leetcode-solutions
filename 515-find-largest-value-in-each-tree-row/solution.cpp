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
    vector<int> largestValues(TreeNode* root) {

        if(!root) return {};
        
        vector<int> ans;

        queue<TreeNode*> cache;

        ans.push_back(root->val);
        cache.push(root);

        while(!cache.empty()){

            int n = cache.size();

            int maxi = INT_MIN;

            while(n > 0){

                TreeNode* curr = cache.front();

                cache.pop();

                if(curr->left){
                    maxi = max(curr->left->val, maxi);
                    cache.push(curr->left);
                }

                if(curr->right){
                    maxi = max(curr->right->val, maxi);
                    cache.push(curr->right);
                }

                n--;
            }

            ans.push_back(maxi);
        }

        ans.pop_back();

        return ans;
    }
};