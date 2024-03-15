class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1 2 6 24
        // 24 24 12 4
        int n = nums.size();
        int prf = 1;
        vector<int> ans(n,1);
        for(int i = 0;i<n;i++){
            ans[i] = prf;
            prf *= nums[i];
        }

        int suf = 1;
        for(int i = n-1;i>= 0;i--){
            ans[i] *= suf;
            suf *= nums[i];
        }
        return ans;

    }
};