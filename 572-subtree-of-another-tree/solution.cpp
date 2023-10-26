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
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        if(isSameTree(root, subRoot)) return true;
        
        bool b1 = (root->left != NULL) ? isSubtree(root->left, subRoot) : false;
        bool b2 = (root->right != NULL) ? isSubtree(root->right, subRoot) : false;

        return b1 || b2;
    }

    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p != NULL && q != NULL){
            if(q->val != p->val) return false;
        }
        else if( (p == NULL && q != NULL) || (p != NULL && q == NULL) ) return false;
        else return true;
        
        bool b1 = isSameTree(p->left, q->left);
        bool b2 = isSameTree(p->right, q->right);

        return b1 && b2;
    }
};