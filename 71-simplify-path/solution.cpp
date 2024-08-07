class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>cache;

        string word = "";

        for(int i = 0; i < path.size(); i++){
            if(path[i] != '/'){
                word += path[i];
            }
            else{
                if(word == ".."){
                    if(!cache.empty()) cache.pop();
                    word = "";
                    continue;
                }
                else if(word != "." && word != ""){
                    cache.push(word);
                }
                word = "";
            }
        }

        if(word != ""){
            if(word == ".."){
                if(!cache.empty()) cache.pop();
            }
            else if(word != ".") cache.push(word);
        }

        string sol = "";

        while(!cache.empty()){
            word = cache.top();

            cout << word << " ";

            sol.insert(0, "/" + word);

            cache.pop();
        }

        if(sol == "") sol += "/";

        return sol;
    }
};