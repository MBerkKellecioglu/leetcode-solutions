class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> sol;

        string curr = "";

        int sz = s.size();

        track(sol, s, curr, 0, 0, sz);

        return sol;
        
    }

    void track(vector<string>& sol, string& s, string& curr, int steps, int ind, int& sz){

        if(steps == 4){
            if(curr.size() == sz + 4){
                curr.pop_back();
                sol.push_back(curr);
                curr += ".";
            }
            return;
        }

        if(sz - (int(curr.size()) - steps) - 1 >= 3 - steps){
            string tmp = s.substr(ind, 1);

            curr += tmp + ".";
                
            track(sol, s, curr, steps + 1, ind + 1, sz);

            curr.erase(curr.begin() + int(curr.size()) - 2, curr.end());
        }
        else return;

        if(sz - (int(curr.size()) - steps) - 2 >= 3 - steps){
            string tmp = s.substr(ind, 2);

            if(tmp[0] != '0'){
                curr += tmp + ".";
                
                track(sol, s, curr, steps + 1, ind + 2, sz);

                curr.erase(curr.begin() + int(curr.size()) - 3, curr.end());
            }
        }
        else return;
        

        if(sz - (int(curr.size()) - steps) - 3 >= 3 - steps){
            string tmp = s.substr(ind, 3);

            if(stoi(tmp) < 256 && tmp[0] != '0'){
                curr += tmp + ".";
                
                track(sol, s, curr, steps + 1, ind + 3, sz);

                curr.erase(curr.begin() + int(curr.size()) - 4, curr.end());
            }
        }

    }
};