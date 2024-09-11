class DetectSquares {
private:
    map<vector<int>, int> freq;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point){
        if(freq.find(point) == freq.end()) freq.insert({point, 1});
        else freq[point]++;
    }
    
    int count(vector<int> point) {
        int sol = 0;
        
        rec_count(point, {}, {}, {}, 1, sol);

        return sol;
    }

    void rec_count(vector<int> q1, vector<int> q2, vector<int> q3, vector<int> q4, int count, int&sol){


        if(q2.empty()){
            for(auto elements : freq){
                if(q1[1] == elements.first[1] && q1[0] != elements.first[0]){
                    rec_count(q1, elements.first, {}, {}, count * elements.second, sol);
                }
            }
        }
        else if(q3.empty()){
            for(auto elements : freq){
                if(q1[0] == elements.first[0] && q1[1] != elements.first[1] && abs(q1[0] - q2[0]) == abs(q1[1] - elements.first[1])){
                    rec_count(q1, q2, elements.first, {}, count*elements.second, sol);
                }
            }
        }
        else if(q4.empty()){
            for(auto elements : freq){
                if(q2[0] == elements.first[0] && q3[1] == elements.first[1]){
                    sol += count * elements.second;
                }
            }
        }
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */