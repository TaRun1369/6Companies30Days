class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> h1(26,0),h2(26,0);

        for(int i = 0;i<word1.size();i++){
            h1[word1[i] - 'a']++;
            h2[word2[i] - 'a']++;

        }

        unordered_map<int,int> mp;

        for(int i = 0;i<26;i++){
            mp[h1[i]]++;
            mp[h2[i]]--; 
        }
        // if(mp.size() == 0) return true;
        for(auto it : mp){
            if(it.second != 0) return false;
        }
        for(int i = 0;i<26;i++){
            if((h1[i] != 0 && h2[i] == 0 )|| (h2[i] != 0 && h1[i] == 0)) return false;
        }
        return true;

    }
};