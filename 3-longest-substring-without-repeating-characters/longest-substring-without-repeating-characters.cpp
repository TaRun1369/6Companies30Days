class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(1000,0);
        int j = 0,n = s.size(),ans = 0;
        if(n == 0) return 0;
        for(int i = 0;i<n;i++){
            hash[s[i]]++;
            if(hash[s[i]] > 1){
                while(j < n && hash[s[i] ] > 1){
                    hash[s[j]]--;
                    j++;
                }

            }
            else{
                ans = max(ans,i - j +1);
            }

        }
        return ans;
    }
};