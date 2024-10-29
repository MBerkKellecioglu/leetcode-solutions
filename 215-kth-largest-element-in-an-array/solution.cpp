class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> max_heap;

        for(int i = 0; i < nums.size(); i++){
            max_heap.push(nums[i]);
        }

        while(k > 1){
            max_heap.pop();
            k--;
        }

        return max_heap.top();
    }
};