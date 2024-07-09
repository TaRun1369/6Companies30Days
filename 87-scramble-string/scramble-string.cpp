class Solution {
public:
unordered_map<string,bool> mp;
    bool recur(string s1,string s2){
        int n = s1.size();
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        bool result = false;
        string key = s1+ "_" + s2;
        if(mp.find(key) != mp.end()) return mp[key];

        for(int i = 1;i<s1.size();i++){
            bool swapp = recur(s1.substr(0,i),s2.substr(n-i,i)) && recur(s1.substr(i,n-i),s2.substr(0,n-i));
            bool no_swap = recur(s1.substr(0,i),s2.substr(0,i)) && recur(s1.substr(i,n-i),s2.substr(i,n-i));

            result |= (swapp | no_swap); 
            if(result == true) break;
        }
        return  mp[key] = result;
    }
    bool isScramble(string s1, string s2) {
        
        bool ans = recur(s1,s2);
        return ans;
    }
};