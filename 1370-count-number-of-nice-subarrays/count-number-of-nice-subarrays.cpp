class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0,sum = 0;
        
        unordered_map<int,int> mp;
        for(auto it : nums){
            if(it%2 != 0) sum++;
            if(sum == k) ans++;
            if(mp.count(sum - k)) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};