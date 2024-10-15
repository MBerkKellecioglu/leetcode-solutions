class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> sol;
        
        for(int i = 0; i < pow(2,n); i++){

            sol.push_back(i^(i >> 1)); //This is literally how you generate gray code//

            // Bitshift to the right and xor with itself and there goes the magic //
        }

        return sol;
    }
};