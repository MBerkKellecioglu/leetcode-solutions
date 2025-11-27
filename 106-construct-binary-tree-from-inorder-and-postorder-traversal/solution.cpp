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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        TreeNode* ans = new TreeNode();

        map<int,int> inmap;

        for(int i = 0; i < inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        construct(ans, inmap, postorder, 0, inorder.size() - 1, postorder.size() - 1);

        return ans;
    }

    void construct(TreeNode*& root, map<int, int>& inmap, vector<int>& postorder, int li, int ri, int pi){

        root->val = postorder[pi];

        int ind = inmap[root->val];

        if(ind - 1 - li + 1 > 0) root->left = new TreeNode();
        if(ri - ind > 0) root->right = new TreeNode();

        if(root->left) construct(root->left, inmap, postorder, li, ind - 1, pi - (ri - ind + 1));
        if(root->right) construct(root->right, inmap, postorder, ind + 1, ri, pi - 1);

        return;
    }
};