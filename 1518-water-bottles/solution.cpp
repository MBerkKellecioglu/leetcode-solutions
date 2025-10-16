class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = numBottles, empty = numBottles;

        numBottles = 0;

        while(empty >= numExchange){
            while(empty >= numExchange){
                empty -= numExchange;
                numBottles++;
            }

            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
        }

        return ans;
    }
};