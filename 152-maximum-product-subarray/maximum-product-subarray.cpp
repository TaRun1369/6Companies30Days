class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 2 0 0 2 3 3 0 0 -4
        // 2 0 0 2 6 18 0 0 -

        int n = nums.size();
        vector<double> pref(n),suff(n);
        double maxi = INT_MIN;
        double pre = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){ pref[i] = 0;
            pre = 1;
            }
            else {
                pre *= nums[i]*1ll;
                pref[i] = pre;}
                 maxi = max(maxi,pref[i]); 
        }
        pre = 1;
        for(int i = n-1;i>=0;i--){
            if(nums[i] == 0){ suff[i] = 0;
            pre = 1;
            }
            else {
                pre *= nums[i]*1ll;
                suff[i] = pre;
                } 

                maxi = max(maxi,suff[i]);
        }


        return (int)maxi;


    }
};