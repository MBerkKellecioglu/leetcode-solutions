class Solution {
public:
    string pushDominoes(string dom) {

        int n = dom.size();

        for(int i = 0; i < dom.size(); i++){
            if(dom[i] == '.'){
                int start_ind = i;

                while(i < dom.size() && dom[i] == '.') i++;

                int end_ind = i - 1;

                Convert(dom, start_ind, end_ind);
            }
        }

        return dom;
    }

    void Convert(string& dom, int start, int end){
        
        bool l = 0, r = 0;

        if(end + 1 < dom.size() && dom[end + 1] == 'L'){
            r = 1;
        }

        if(start - 1 > -1 && dom[start - 1] == 'R'){
            l = 1;
        }

        if(l == 0 && r == 1){
            for(int i = start; i <= end; i++) dom[i] = 'L';
        }
        else if(l == 1 && r == 0){
            for(int i = start; i <= end; i++) dom[i] = 'R';
        }
        else if(l == 1 && r == 1){
            int sz = end - start + 1;
            int i = start;

            for(int c = 0; c < sz / 2; c++){
                dom[i] = 'R';
                i++;
            }

            if(sz % 2 == 1) i++;

            for(int c = 0; c < sz / 2; c++){
                dom[i] = 'L';
                i++;
            }
        }
    }
};