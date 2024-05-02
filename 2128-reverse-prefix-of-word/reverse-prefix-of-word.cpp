class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";

        int it;

        it = word.find(ch);
        if(it != -1){
            ans += word.substr(0,it+1);
            reverse(ans.begin(),ans.end());
            ans += word.substr(it+1,word.size() - it - 1);
            return ans;
        }
        else {
            return word;
        }
    }
};