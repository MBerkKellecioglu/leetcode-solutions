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
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> cache;

        cache.push(root);

        int ans = 0;

        while(!cache.empty()){

            int n = cache.size();

            vector<int> sorted;

            while(n > 0){

                TreeNode* curr = cache.front();

                cache.pop();

                if(curr->left){
                    sorted.push_back(curr->left->val);
                    cache.push(curr->left);
                }

                if(curr->right){
                    sorted.push_back(curr->right->val);
                    cache.push(curr->right);
                }

                n--;
            }

            vector<int> unsorted = sorted;

            map<int, int> index;

            sort(sorted.begin(), sorted.end());

            for(int i = 0; i < unsorted.size(); i++) index[unsorted[i]] = i;


            for(int i = 0; i < sorted.size(); i++){
                if(sorted[i] != unsorted[i]){

                    int correct_num = sorted[i], wrong_num = unsorted[i];
                    ans++;
                    
                    swap(index[correct_num], index[wrong_num]); // first we swap index values of numbers

                    swap(unsorted[index[correct_num]], unsorted[index[wrong_num]]); // since our index values are correct now we can just swap values
                } 
            }
        }

        return ans;
    }
};