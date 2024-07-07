class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        

        priority_queue<int> max_heap;

        for(int i = 0; i < stones.size(); i++){
            max_heap.push(stones[i]);
        }

        while(max_heap.size() > 1){
            int y = max_heap.top();
            max_heap.pop();

            int x = max_heap.top();
            max_heap.pop();

            max_heap.push(y - x);
        }

        return max_heap.top();
    }
};