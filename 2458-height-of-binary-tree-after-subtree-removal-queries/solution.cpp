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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        map<int, priority_queue<pair<int,int>>> level_heights;

        map<int, int> num_levels;

        vector<int> ans;

        dfs(root, level_heights, num_levels, 0);

        for(auto& q : queries){
            int level = num_levels[q];

            pair<int,int> maxi = level_heights[level].top();

            if(maxi.second != q) ans.push_back(level + maxi.first);
            else{
                level_heights[level].pop();

                if(!level_heights[level].size()) ans.push_back(level - 1);
                else ans.push_back(level + level_heights[level].top().first);

                level_heights[level].push(maxi);
            }
        }

        return ans;
    }

    int dfs(TreeNode* root, map<int, priority_queue<pair<int,int>>>& lh, map<int, int>& nl, int level){
        if(!root) return 0;

        int height = max(dfs(root->left, lh, nl, level + 1), dfs(root->right, lh, nl, level + 1));

        if(lh[level].size() < 2) lh[level].push({height, root->val});
        else{
            pair<int,int> first = lh[level].top();

            if(first.first < height){
                lh[level].pop();
                lh[level].pop();
                lh[level].push(first);
                lh[level].push({height, root->val});
            }
            else{
                lh[level].pop();
                pair<int,int> second = lh[level].top();

                if(second.first < height){
                    lh[level].pop();
                    lh[level].push(first);
                    lh[level].push({height, root->val});
                }
                else lh[level].push(first);
            }
        }

        nl[root->val] = level;

        return height + 1; 
    }
};