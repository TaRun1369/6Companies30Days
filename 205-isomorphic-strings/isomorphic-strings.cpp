class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<int> s1(256,-1),t1(256,-1);
        for(int i = 0;i<n;i++){
            if(s1[s[i]] == -1 && t1[t[i]] == -1){
                s1[s[i]] = t[i];
                t1[t[i]] = s[i];
            }
            
            else{
                if(s1[s[i]] != t[i] || t1[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};