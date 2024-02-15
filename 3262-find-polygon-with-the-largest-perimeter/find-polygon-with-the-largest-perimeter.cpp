class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        unsigned long long sum = accumulate(nums.begin(),nums.end(),0ll);
        cout<<"sum - "<<sum<<endl;
        sort(nums.begin(),nums.end(),greater<int>());

        for(auto it : nums){
            sum -= it;
            cout<<"sum - "<<sum<<endl;
            if(it < sum) {
                return sum + it;
            }

        }
        return -1;
    }
};