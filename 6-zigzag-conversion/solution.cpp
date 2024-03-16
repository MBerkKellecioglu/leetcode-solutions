class Solution {
public:
    string convert(string s, int numRows){

        int inc = numRows + numRows - 2;

        if(numRows >= s.size() || inc == 0) return s;
        
        string sol = "";

        for(int i = 0; i < numRows; i++){
            int ind = i; 
            sol += string(1, s[ind]);

            while(ind < s.size()){
                int dec = i * 2;
                ind += inc;
                if(i != 0 && i != numRows - 1){
                    if(ind - dec < s.size()) sol += string(1, s[ind - dec]);
                }
                if(ind < s.size()) sol += string(1, s[ind]);
            }
        }

        return sol;
    }
};