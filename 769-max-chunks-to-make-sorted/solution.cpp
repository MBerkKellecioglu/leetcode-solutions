class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size(), curr_min = 0, ans = 0;

        int prev_max = -1, curr_max = INT_MIN;

        vector<bool> checked(n, false);

        for(int i = 0; i < n; i++){
            checked[arr[i]] = true;

            curr_max = max(curr_max, arr[i]);

            if(arr[i] == curr_min){
                checked[curr_min] = true;
        
                if(curr_min > prev_max){
                    ans++;
                    prev_max = curr_max;
                    curr_max = INT_MIN;
                }
                else{
                    prev_max = max(prev_max, curr_max);
                    curr_max = INT_MIN;
                }

                curr_min = findNextMin(checked, curr_min);
                cout << curr_min << endl;
            }
        }

        return ans;
    }

    int findNextMin(vector<bool>& checked, int curr_min){

        for(int i = curr_min; i < checked.size(); i++){
            if(!checked[i]) return i;
        }

        return -2;
    }
};