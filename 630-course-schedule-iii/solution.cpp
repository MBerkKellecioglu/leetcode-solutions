class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        priority_queue<int> maxHeap;

        sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1]; // 1. indexe göre sıralama (küçükten büyüğe)
        });

        int totalTime = 0, ans = 0;

        for(int i = 0; i < courses.size(); i++){
            totalTime += courses[i][0];

            maxHeap.push(courses[i][0]);

            while(totalTime > courses[i][1]){
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};