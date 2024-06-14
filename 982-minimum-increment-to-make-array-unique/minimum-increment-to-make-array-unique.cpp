class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {

            int a = nums[i], b = nums[i - 1];
            if (nums[i] <= nums[i - 1]) {
                // while (a <= b) {
                //     a++;
                //     ans++;
                // }
                ans=ans+abs(a-b)+1;
                nums[i]=nums[i]+abs(a-b)+1;
            }
            //nums[i] = a;
        }
        return ans;
    }
};