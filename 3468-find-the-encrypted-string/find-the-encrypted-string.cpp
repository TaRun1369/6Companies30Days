class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        int n = s.size();
        for(int i = k;i< k + s.size();i++){
            ans += s[i%n];
        }
        return ans;
    }
};