class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int mxi = 0;
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0;i<nums.size();i++){
            mxi += (nums[i]*i);
        }
        // cout<<"max - "<<mxi<<endl;
        int prev = mxi;
        for(int i = 0;i<nums.size() - 1;i++){
            // cout<<"index "<<i<<endl;
            int t =prev;
            // cout<<"t = "<<t<<endl;
            t += sum;
            // cout<<"t + sum = "<<t<<endl;
            t -= ((n)* nums[(n-1 - i)]);
            // cout<<"t - last = "<<t<<endl;
            // cout<<"maxb - "<<mxi<<endl;
            mxi = max(mxi , t);
            prev = t;
            // cout<<"maxa - "<<mxi<<endl;
        }
        return mxi;
    }
};