class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());
        int pref = 0,i = 0;
        int n = nums.size();
        for(;i<n;i++){
            pref += nums[i];
            total -=  nums[i];
            if(pref > total){
                break;
            }
        }

        vector<int> ans(nums.begin(),nums.begin() + i + 1);
        return ans;
    }
};