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
    
    bool search(string word){
        Node* curr = root;

        for(char c : word){
            if(!curr->contains(c)) return false;
            curr = curr->get(c);
        }

        if(curr->blue != true) return false;

        return true;
    }
    
    bool startsWith(string prefix){
        Node* curr = root;

        for(char c : prefix){
            if(!curr->contains(c)) return false;
            curr = curr->get(c);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */