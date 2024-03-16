class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int pref = 0,n= nums.size();
        map<int,int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            
            if(nums[i] == 0)pref -= 1;
            else pref += 1;

            if(mp.find(pref)  != mp.end()) {
                ans = max(ans,i - mp[pref]);
            }
            else{
                mp[pref] = i;
            }
            
        }
        return ans;
    }
};