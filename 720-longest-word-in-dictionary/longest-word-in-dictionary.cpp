
class Node{
    public:
    Node* links[26];//reference link for each node - 26 characters i.e. 26 links
    bool flag = false; // end of word checking flag 
    bool containsKey(char ch){ // to check if character exist or not
        return links[ch-'a']!=NULL;
    }

     void put(char ch,Node* node){
        // to add ch char link
        links[ch-'a'] = node;
     }

     Node* get(char ch){
        return links[ch - 'a'];
     }

     void setEnd(){
        flag = true;
     }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto it : word){
            if(!node->containsKey(it)){
                node->put(it,new Node());
            }
            // move to reference of this character 
            node = node->get(it);
             
        }
        node->setEnd();
    }

    bool search(string word){ 
        // to check if word exist or not
        Node* node = root;
        for(auto it : word){
            if(!node->containsKey(it)){
                return false;
            }
            node = node->get(it);
        }
        return node->flag;
    }

    bool startsWith(string prefix){
        // to check if input is prefix of any word
        Node* node = root;
        for(auto it: prefix){
            if(!node->containsKey(it)){
                return false;
            }
            node = node->get(it);
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        Trie t;
        for(auto it : words){
            t.insert(it);
        }

        for(auto it: words){
            string temp = "";
            int f = 0;
            for(auto is : it){
                temp += is;
                if(t.search(temp) == false){
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                if(ans.size() < it.size()){
                    ans = it;
                }
                else if(ans.size() == it.size()){
                    ans = min(ans,it);
                }
            }
        }
        return ans;
    }
};