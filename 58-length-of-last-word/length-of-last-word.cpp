class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string w;
        int ans;
        while(ss >> w){
            ans = w.size();
        }
        return ans;

    }
};