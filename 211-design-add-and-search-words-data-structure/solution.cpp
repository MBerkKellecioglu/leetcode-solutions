class Node{
public:
    Node* child[26];
    bool blue = false;

    Node(){
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    }

    bool contains(char& c){
        return (child[c - 97] != nullptr);
    }

    bool contains(int& i){
        return child[i] != nullptr;
    }

    Node* get(char& c){
        return child[c - 97];
    }

    Node* get(int& i){
        return child[i];
    }

    void put(char& c){
        child[c - 97] = new Node();
    }     
};


class WordDictionary {
private:
    Node *root;

public:
    WordDictionary() {
        root = new Node();    
    }
    
    void addWord(string word){
        Node* curr = root;


        for(char c : word){
            if(!curr->contains(c)) curr->put(c);
            curr = curr->get(c);
        }

        curr->blue = true;
    }
    
    bool search(string word){

        Node* curr = root;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                bool flag = false;
                dfs(curr, word, i, flag);
                return flag;
            }
            else{
                if(curr->contains(word[i])){
                    curr = curr->get(word[i]);
                    continue;
                }
                else return false;
            }
        }

        if(curr->blue != true) return false;
        return true;
    }

    void dfs(Node* curr, string& word, int ind, bool& flag){
        
        if(ind == word.size()){
            if(curr->blue == true) flag = true;
            return;
        }

        if(word[ind] == '.'){
            for(int i = 0; i < 26; i++){
                if(curr->contains(i)){
                    dfs(curr->get(i), word, ind + 1, flag);
                }
            }
            return;
        }
        else{
            if(curr->contains(word[ind])) dfs(curr->get(word[ind]), word, ind + 1, flag);
            else return;
        }
    }

};