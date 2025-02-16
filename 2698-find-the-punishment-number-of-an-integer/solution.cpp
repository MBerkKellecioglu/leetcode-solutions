


class Solution { 
public:
    set<int> punish;
    int highest = 0;

    int punishmentNumber(int n) {

        int max_digits = 0, sum = 0, ans = 0, i = 0;

        if(n < highest){
            for(int e : punish) ans += e;

            return ans;
        }
        else{
            i = highest;
            highest = n;
        }

        bool flag = false;

        string s = "";
        
        for(i = 1; i < n + 1; i++){
            max_digits = findDigits(i);
            s = to_string(i * i);
            flag = false;

            partition(i, s, max_digits, 0, sum, flag);

            if(flag){
                ans += stoi(s);
                punish.insert(i);
            }
        }

        return ans;
    }

    void partition(int& num, string& s, int& max_digits, int ind, int& sum, bool& flag){

        if(ind >= s.size()){
            if(sum == num){
                flag = true;
                return;
            }
        }

        for(int i = 1; i <= max_digits; i++){
            if(ind + i - 1 < s.size()){
                int addition = stoi(s.substr(ind, i));

                sum += addition;

                if(!flag) partition(num, s, max_digits, ind + i,  sum, flag);

                sum -= addition;
            }
            else break;
        }
    }

    int findDigits(int n){

        int ans = 0;

        while(n > 0){
            n /= 10;
            ans++;
        }

        return ans;   
    }
};