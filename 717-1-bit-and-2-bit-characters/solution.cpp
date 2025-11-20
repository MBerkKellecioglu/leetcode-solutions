class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int next = 0, n = bits.size();

        for(int i = 0; i < n; i++){
            if(next >= n) return false;

            if(bits[i] == 1){
                next = i + 2;
                i++;
            }
        }

        if(next >= n) return false;
        
        return true;
    }
};