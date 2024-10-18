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
    vector<TreeNode*> generateTrees(int n){

        map<pair<int,int>, vector<TreeNode*>> dp;


        return construct(dp, 1, n);

    }

    vector<TreeNode*> construct(map<pair<int,int>, vector<TreeNode*>>& dp, int left, int right){

        if(left > right) return {nullptr};

        if(dp.find({left, right}) != dp.end()){
            return dp[{left, right}];
        }

        vector<TreeNode*> sol;

        for(int i = left; i <= right; i++){
            vector<TreeNode*> left_nodes = construct(dp, left, i - 1);
            vector<TreeNode*> right_nodes = construct(dp, i + 1, right);

            for(TreeNode* n1 : left_nodes){
                for(TreeNode* n2 : right_nodes){
                    TreeNode* root = new TreeNode(i, n1, n2);
                    sol.push_back(root);
                }
            }
        }

        dp[{left, right}] = sol;

        return sol;
    }
    
};