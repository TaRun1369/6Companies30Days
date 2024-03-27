class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            // cout<<nums[i]<<endl;
            int j = i;
            int tem  = 1;
            while(tem < k && j < n){
                tem*= nums[j];
                j++;
                // cout<<j<<" - j pe tem =  "<<tem<<endl;
            }
            int c;
            if(tem >= k)
             c = j - i - 1;
             else c = j-i;
         
            if(c > 0)
            ans += c;
            // cout<<"ans - "<<ans<<endl;
        }
        return ans;
    }
};