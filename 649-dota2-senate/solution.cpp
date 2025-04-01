class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> r;
        queue<int> d;

        int n = senate.size();

        for(int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        while(!r.empty() && !d.empty()){
            int ind;

            if(r.front() < d.front()){
                ind = r.front();
                r.pop();
                d.pop();

                r.push(ind + n);
            }
            else{
                ind = d.front();
                d.pop();
                r.pop();

                d.push(ind + n);
            }
        }

        return (r.empty()) ? "Dire" : "Radiant";
    }
};