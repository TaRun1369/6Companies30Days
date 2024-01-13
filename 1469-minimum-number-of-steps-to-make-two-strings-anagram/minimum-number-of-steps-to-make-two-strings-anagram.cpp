class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash1(26,0) ,hash2 (26,0);

        for(auto it : s){
            hash1[it - 'a']++;
        }

        for(auto it : t){
            hash2[it - 'a']++;
        }
        int ans= 0;
        for(int i = 0;i<26;i++){
             ans += abs(hash1[i] - hash2[i]);

        }

        return ans/2;
    }
};