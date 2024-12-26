struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second){
            return a.first > b.first;
        }
        else{
            return a.second > b.second;
        }
    }
};


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> minHeap;

        for(int i = 0; i < nums.size(); i++){
            minHeap.push({i, nums[i]});
        }

        for(int i = 0; i < k; i++){
            pair<int, int> tmp = minHeap.top();

            minHeap.pop();

            nums[tmp.first] *= multiplier;
            tmp.second *= multiplier;

            minHeap.push(tmp);
        }

        return nums;
    }
};