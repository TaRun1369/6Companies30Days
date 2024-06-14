class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // 1 1 2 2 3 7
        // 1 ka upper bound   - (2 - 0) = no. of ones

        map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
        }
        int ans = 0;
        for(auto &it : mp){
            if(it.second > 1){
                int rem = it.second - 1;
                it.second -= rem;
                mp[it.first + 1] += rem;
                ans += rem;
            }
        }
        return ans;
    }
};