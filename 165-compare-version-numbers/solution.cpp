class Solution {
public:
    int compareVersion(string s1, string s2) {

        s1 += ".";
        s2 += ".";
        
        int l1 = 0, r1 = 0, v1 = 0, n1 = s1.size();
        int l2 = 0, r2 = 0, v2 = 0, n2 = s2.size();

        while(r1 < n1 || r2 < n2){
            while(r1 < n1 && s1[r1] != '.') r1++;

            if(r1 < n1) v1 = stoi(s1.substr(l1, r1 - l1));

            while(r2 < n2 && s2[r2] != '.') r2++;

            if(r2 < n2) v2 = stoi(s2.substr(l2, r2 - l2));

            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;

            l1 = r1 + 1;
            r1++;
            v1 = 0;

            l2 = r2 + 1;
            r2++;
            v2 = 0;
        }

        return 0;
    }
};