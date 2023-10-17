class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int left = 0, right = 0;
        deque<int> cache;
        vector<int> sol;

        while(right < nums.size()){
            // making sure that our deque is a heap by making it descending ordered //
            while(!cache.empty() && nums[right] > nums[cache.back()]) cache.pop_back(); 
            
            // adding our index to right of the queue //
            cache.push_back(right); 

            // cheking whether if our index is out of sliding window borders //
            if(left > cache.front()) cache.pop_front(); 
            
            if(right + 1 >= k){ 
                // for every sliding window we have max so if right(index) is bigger than //
                // windows size that means we should start adding our max numbers //
                sol.push_back(nums[cache.front()]);

                left++; //incrementing left border of our window //
            }
            right++;
        }

        return sol;
    }
};