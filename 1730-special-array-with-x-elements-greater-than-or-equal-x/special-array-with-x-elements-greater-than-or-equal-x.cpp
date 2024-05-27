class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n;
        while(l <= r){
            int mid = (l + r)/2;
            int lowie = lower_bound(nums.begin(),nums.end(),mid) - nums.begin();
            cout<<"lower - "<<lowie<<"    mid - "<<mid<<endl;
            if(n- lowie == mid) return mid;
            else if(n - lowie > mid ) l = mid + 1;
            else r = mid -1;
        }

        return -1;
    }
};