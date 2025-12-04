class Solution {
public:
    int countCollisions(string directions){

        int ans = 0, flag = -1;

        for(int i = 0; i < directions.size(); i++){

            if(directions[i] == 'L'){
                if(flag >= 0){
                    ans += flag + 1;
                    flag = 0;
                }
            }
            else if(directions[i] == 'S'){
                if(flag > 0){
                    ans += flag;
                }
                flag = 0;
            }
            else{
                if(flag >= 0) flag++;
                else flag = 1;
            }
        }

        return ans;
    }
};