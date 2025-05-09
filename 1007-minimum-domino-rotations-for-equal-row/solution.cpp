class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        map<int, int> top_freq;
        map<int, int> bot_freq;
        
        // first number then freq
        vector<pair<int, int>> top_cand = {{0, 0}};
        vector<pair<int, int>> bot_cand = {{0, 0}};

        for(int i = 0; i < tops.size(); i++){
            top_freq[tops[i]]++;
            bot_freq[bottoms[i]]++;
        }

        for(auto p : top_freq){
            if(top_cand[0].second < p.second){
                top_cand = {{p.first, p.second}};
            }
            else if(top_cand[0].second == p.second){
                top_cand.push_back({p.first, p.second});
            }
        }

        for(auto p : bot_freq){
            if(bot_cand[0].second < p.second){
                bot_cand = {{p.first, p.second}};
            }
            else if(bot_cand[0].second == p.second){
                bot_cand.push_back({p.first, p.second});
            }
        }

        int ans1 = INT_MAX, ans2 = INT_MAX;
        
        for(auto e : top_cand){
            ans1 = min(ans1, Validate(tops, bottoms, e.first, 1));
        }

        for(auto e : bot_cand){
            ans2 = min(ans2, Validate(tops, bottoms, e.first, 0));
        }

        if(ans1 == INT_MAX && ans2 == INT_MAX) return -1;

        return min(ans1, ans2);
    }

    int Validate(vector<int> top, vector<int> bot, int num, bool key){

        int valid = 0, operation = 0;

        for(int i = 0; i < top.size(); i++){
            if(key){
                if(top[i] != num){
                    if(bot[i] == num){
                        valid++;
                        operation++;
                    }
                }
                else valid++;
            }
            else{
                if(bot[i] != num){
                    if(top[i] == num){
                        valid++;
                        operation++;
                    }
                }
                else valid++;
            }
        }

        return (valid == top.size()) ? operation : INT_MAX;
    }
};