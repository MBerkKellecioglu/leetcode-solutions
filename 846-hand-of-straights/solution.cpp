class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gsz){ // gsz stands for group size 

        if(hand.size() % gsz != 0) return false;

        map<int, int> freq;

        for(int i = 0; i < hand.size(); i++) freq[hand[i]]++;
        
        for(auto& elements : freq){
            if(elements.second != 0){
                int count = elements.second;        
                if(!cons(freq, elements.first, gsz, count)){ 
                    return false;
                }
            }
        }

        return true;
    }

    bool cons(map<int,int>& freq, int key, int gsz, int& count){

        if(gsz == 1){
            if(freq[key] >= count){
                freq[key] -= count;
                return true;
            }
            else return false;
        }

        if(freq[key] >= count && cons(freq, key + 1, gsz - 1, count)){
            freq[key] -= count;
        }
        else return false;

        return true;

    }
};