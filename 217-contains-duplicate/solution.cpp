
auto init = []()
{ ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> cache;

        for(int elements : nums){
            cache[elements]++;
            if(cache[elements] > 1) return true;
        }

        return false; 
    }
};