string operator *(string s, int b){
        string multiplied;
        for(int i = 0; i < b; i++) multiplied += s;
        return multiplied;
}
class Solution {
public:
    string decodeString(string s){
        string num_convert;
        string sol;
        int converted_num = 1, open_count = 0, first_ind;

        if(s.find("[") == string::npos) return s;

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                while(isdigit(s[i + 1])){
                    num_convert += s[i];
                    i++;
                }
                num_convert += s[i];
                converted_num = stoi(num_convert);
                num_convert = "";
            }
            else if(s[i] == '['){
                open_count++;
                first_ind = i + 1;
                while(open_count != 0){
                    if(s[i + 1] == ']') open_count--;
                    if(s[i + 1] == '[') open_count++;
                    i++;
                }
                string tmp_s = s.substr(first_ind, i - first_ind);
                sol += decodeString(tmp_s) * converted_num;
            }
            else sol += s[i];
        }
        return sol;
    }
};