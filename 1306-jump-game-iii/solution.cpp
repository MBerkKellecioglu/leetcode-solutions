class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        
        queue<int> q; // index values

        vector<bool> checked(n, false);

        q.push(start);

        checked[start] = true;

        while (q.size()){

            int ind = q.front();
            int num = arr[ind];
            q.pop();

            if (arr[ind] == 0) return true;

            if(ind + num < n && !checked[ind + num]){
                q.push(ind + num);
                checked[ind + num] = true;
            }

            if(ind - num > -1 && !checked[ind - num]){
                q.push(ind - num);
                checked[ind - num] = true;
            }
        }

        return false;
    }
};