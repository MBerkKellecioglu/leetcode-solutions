class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){

        priority_queue<vector<int>> max_heap;

        vector<vector<int>> sol;

        for(int i = 0; i < points.size(); i++){
            max_heap.push({manhattan(points[i]), i});
        }

        while(max_heap.size() > k){
            max_heap.pop();
        }

        while(max_heap.size() > 0){
            sol.push_back(points[max_heap.top()[1]]);
            max_heap.pop();
        }

        return sol;
    }

    int manhattan(vector<int> point){

        return pow(point[0],2) + pow(point[1],2);
    }
};