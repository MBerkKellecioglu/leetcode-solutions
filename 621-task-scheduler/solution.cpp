class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char, int> freq;
        int sol = 0, curr = -1;

        for(auto elements : tasks){
            freq[elements]++;
        }

        priority_queue<int> max_heap;
        queue<pair<int,int>> time;

        for(auto elements : freq){
            max_heap.push(elements.second);
        }

        while(!max_heap.empty() || !time.empty()){
            sol++;
            curr = -1;

            if(!max_heap.empty()){
                curr = max_heap.top();
                max_heap.pop();
                curr--;
            }

            if(!time.empty()){
                if(time.front().first == sol){
                    max_heap.push(time.front().second);
                    time.pop();
                }
            }

            if(curr > 0) time.push({sol + n, curr});
        }

        return sol;
    }
};