class Solution {
    using ll = long long;
public:
    long long minEnd(int n, int x){

        int j = 0;

        bitset<64> num = x;
        // the combination of bits we must convert at our base num (x). We convert zeros of our number(x)
        bitset<64> combination = n - 1; 

        /* for example n = 3, so our combination is 2 (10) and our base number
           is 4(100), we must convert that 2 zeros to 10 so it becomes (110)*/

        for(int i = 0; i < 64; i++){
            if(!num[i]){
                if(combination[j]) num[i] = 1;
                j++;
            }
        }

        return num.to_ullong();   
    }
};