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

    Node* get(char& c){
        return child[c - 97];
    }

    void put(char& c){
        child[c - 97] = new Node();
    }

    bool ifWord(Node* cursor){
        if(cursor->blue) return true;

        return false;
    }

    void turnColor(Node* cursor){
        cursor->blue = false;
    } 
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word){
        Node* curr = root;

        for(char c : word){
            if(!curr->contains(c)) curr->put(c);
            curr = curr->get(c);
        }

        curr->blue = true;
    }
     
    bool startsWith(char& c, Node*& cursor){
        Node* curr = (cursor == nullptr) ? root : cursor;

        if(c == '!') return false;

        if(!curr->contains(c)) return false;
        curr = curr->get(c);
        
        cursor = curr;

        return true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Trie* new_try = new Trie();
        vector<string> sol;
        
        for(string word : words) new_try->insert(word);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                Node* cursor = nullptr;
                if(new_try->startsWith(board[i][j], cursor)){
                    string currword;
                    RecWord(board, sol, currword, cursor, new_try, i, j);
                }
            }
        }

        return sol;
    }

    void RecWord(vector<vector<char>>& board, vector<string>& sol, string& currword, Node* cursor, Trie* new_try, int x, int y){

        if(cursor->ifWord(cursor)){
            currword += string(1, board[x][y]);
            sol.push_back(currword);
            cursor->turnColor(cursor);
            currword.erase(currword.size() - 1);
        }
        
        Node* tmp_ptr = cursor; 
        char tmp = board[x][y];
        board[x][y] = '!';

        currword += string(1, tmp);

        if(x + 1 < board.size() && new_try->startsWith(board[x + 1][y], cursor)) RecWord(board, sol, currword, cursor, new_try, x + 1, y);
        cursor = tmp_ptr;
        if(x - 1 > -1 && new_try->startsWith(board[x - 1][y], cursor)) RecWord(board, sol, currword, cursor, new_try, x- 1, y);
        cursor = tmp_ptr;
        if(y + 1 < board[0].size() && new_try->startsWith(board[x][y + 1], cursor)) RecWord(board, sol, currword, cursor, new_try, x, y + 1);
        cursor = tmp_ptr;
        if(y - 1 > -1 && new_try->startsWith(board[x][y - 1], cursor)) RecWord(board, sol, currword, cursor, new_try, x, y - 1);

        board[x][y] = tmp;
        cursor = tmp_ptr;
        currword.erase(currword.size() - 1);
    }
};