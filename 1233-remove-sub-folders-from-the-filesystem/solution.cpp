class Node{
public:
    map<string, Node*> child;
    bool blue = false;

    Node(){
    }

    bool contains(string& s){
        return (child.find(s) != child.end()) ? true : false;
    }

    Node* get(string& s){
        return child[s];
    }

    Node* put(string& s){
        return child[s] = new Node();
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(vector<string>& list, bool& del){
        Node* curr = root;

        for(int i = 0; i < list.size(); i++){
            string s = list[i];

            if(curr->contains(s)){
                curr = curr->get(s);
                if(i != list.size() - 1 && curr->blue){
                    del = true;
                    break;
                }
            }
            else curr = curr->put(s);
        }

        curr->blue = true;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        Trie* trie = new Trie();

        string word = "";

        vector<string> ans;

        sort(folder.begin(), folder.end());

        for(int i = 0; i < folder.size(); i++){

            int l = 1, r = 1;
            vector<string> sub_folder;
            string s = folder[i];

            while(r < s.size()){
                while(r < s.size() && s[r] != '/'){
                    r++;
                }

                sub_folder.push_back(s.substr(l, r - l));

                l = r + 1;
                r++;
            }

            bool del = false;
            trie->insert(sub_folder, del);

            if(!del){
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};