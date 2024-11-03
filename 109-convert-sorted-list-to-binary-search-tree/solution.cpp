/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;

        vector<int> nums;

        ListNode* curr = head;

        while(curr != nullptr){
            nums.push_back(curr->val);
            curr = curr->next;
        }

        return createBST(nums, 0, nums.size() - 1);
    }

    TreeNode* createBST(vector<int>& nums, int l, int r){

        if(r < l || r >= nums.size() || l < 0) return nullptr;

        int mid = l + (r - l) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = createBST(nums, l, mid - 1);
        root->right = createBST(nums, mid + 1, r);

        return root;
    }
};