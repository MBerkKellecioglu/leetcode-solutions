class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double,double>> maxHeap;

        double ans = 0;

        for(int i = 0; i < classes.size(); i++){
            double avg = (double(classes[i][0] + 1) / double(classes[i][1] + 1)) - (double(classes[i][0]) / double(classes[i][1]));

            maxHeap.push({avg, i});
        }

        for(int i = 0; i < extraStudents; i++){
            pair<double, double> tmp = maxHeap.top();

            maxHeap.pop();

            classes[tmp.second][0] += 1;
            classes[tmp.second][1] += 1;

            tmp.first = (double(classes[tmp.second][0] + 1) / double(classes[tmp.second][1] + 1)) - (double(classes[tmp.second][0]) / double(classes[tmp.second][1]));

            maxHeap.push(tmp);
        }

        for(int i = 0; i < classes.size(); i++){
            ans += double(classes[i][0]) / double(classes[i][1]); 
        }

        return ans / double(classes.size());
    }
};