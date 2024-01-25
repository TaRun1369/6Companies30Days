class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size();
        int i = 0,j = 0;
        unordered_map<int,int> mp;
        while(j < nums.size()){
            mp[nums[j]]++;

            if(mp[nums[j]] > k){
                maxi = max(maxi,j-i);
                while(i < n && mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        maxi = max(maxi,j-i);
        return maxi;
    }
};