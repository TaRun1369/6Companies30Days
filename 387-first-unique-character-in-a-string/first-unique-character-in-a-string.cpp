class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> hash(26,0);
        for(auto it : s){
        hash[it - 'a']++;
        }
        for(int i = 0;i<n;i++){
        if(hash[s[i] - 'a']==1){
        return i;
        }
        }
        return -1;
    }
};