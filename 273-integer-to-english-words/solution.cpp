class Solution {
public:
    string numberToWords(int num){

        if(num == 0) return "Zero";

        string number = to_string(num);
        string sol = "";
        string chunk = "";

        map<string, vector<string>> converter = {
            {"0", {"", ""}},
            {"1", {"One"}},
            {"2", {"Two", "Twenty"}},
            {"3", {"Three", "Thirty"}},
            {"4", {"Four", "Forty"}},
            {"5", {"Five", "Fifty"}},
            {"6", {"Six", "Sixty"}},
            {"7", {"Seven", "Seventy"}},
            {"8", {"Eight", "Eighty"}},
            {"9", {"Nine", "Ninety"}},
            {"10", {"Ten"}},
            {"11", {"Eleven"}},
            {"12", {"Twelve"}},
            {"13", {"Thirteen"}},
            {"14", {"Fourteen"}},
            {"15", {"Fifteen"}},
            {"16", {"Sixteen"}},
            {"17", {"Seventeen"}},
            {"18", {"Eighteen"}},
            {"19", {"Nineteen"}}
        };

        map<int, string> levels = {
            {1, ""},
            {2, "Thousand"},
            {3, "Million"},
            {4 , "Billion"}
        };

        int level = 1;

        for(int i = number.size() - 1; i > -1; i--){
            chunk.insert(0, string(1, number[i]));

            if(chunk.size() == 3 || i == 0){
                chunk = helper(converter, levels, chunk, level);
                if(chunk != ""){
                    if(chunk[0] != ' ') chunk.insert(0, " ");
                    if(level != 1) chunk += " " + levels[level];
                    sol.insert(0, chunk);
                }
                level++;
                chunk = "";
            }
        }

        if(sol[0] == ' ') sol.erase(sol.begin());

        return sol;   
    }

    string helper(map<string, vector<string>>&converter, map<int, string>&levels, string& chunk, int& level){

        string converted = "";

        if(chunk.size() < 3){
            while(chunk.size() < 3) chunk.insert(0, "0");
        }

        for(int i = 0; i < chunk.size(); i++){
            if(chunk[i] == '0') continue;

            if(i == 0){
                converted += converter[string(1, chunk[i])][0] + " " + "Hundred";
            }
            else if(i == 1){
                if(chunk[i] == '1'){
                    converted += " " + converter[chunk.substr(1,2)][0];
                    break;
                }
                else{
                    converted += " " + converter[string(1, chunk[i])][1];
                }
            }
            else{
                converted += " " + converter[string(1, chunk[i])][0];
            }
        }
        
        return converted;
    }
};