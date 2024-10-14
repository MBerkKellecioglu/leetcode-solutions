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
    void recoverTree(TreeNode* root) {
        
        vector<TreeNode*> nodes;
        vector<int> sorted;

        dfs(root, nodes);

        for(int i =0 ; i < nodes.size(); i++){
            sorted.push_back(nodes[i]->val);
        }

        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < nodes.size(); i++){
            nodes[i]->val = sorted[i];
        }
    }

    void dfs(TreeNode* root, vector<TreeNode*>&nodes){

        if(root == nullptr) return;
        

        dfs(root->left, nodes);
        nodes.push_back(root);
        dfs(root->right, nodes);

    }
};