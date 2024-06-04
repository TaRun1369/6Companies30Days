class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(256,0);
        int ans = 0;
        for(auto it : s) hash[it]++;
        int odd = 0;
        for(auto it : hash) {
            if(it % 2 != 0){ odd = 1;
            ans += it - 1;
            }
            else ans += it;
        
        }

        return ans + odd;
    }
};