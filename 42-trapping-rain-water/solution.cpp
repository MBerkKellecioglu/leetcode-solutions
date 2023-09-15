class Solution {
public:
    int trap(vector<int>& height){
        int left_max = height[0], right_max = height[height.size() - 1] , max_ind = max_element(height.begin(), height.end()) - height.begin(), left_ind = 1, right_ind = height.size() - 2, count = 0;

        while(left_ind < max_ind || right_ind > max_ind){
            if(left_max < height[left_ind]) left_max = height[left_ind];
            if(right_max < height[right_ind]) right_max = height[right_ind];
            if(left_max - height[left_ind] > 0 && left_ind < max_ind) count += left_max - height[left_ind];
            if(right_max - height[right_ind] > 0 && right_ind > max_ind) count += right_max - height[right_ind];
            left_ind++;
            right_ind--;
        }

        return count;
    }
};