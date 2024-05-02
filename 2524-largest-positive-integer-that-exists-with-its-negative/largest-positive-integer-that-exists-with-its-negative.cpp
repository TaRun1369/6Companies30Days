class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        sort(nums.rbegin(),nums.rend());
        unordered_set<int> s;
        for(auto it: nums){
            if(it > 0){
                s.insert(it);
            }
            else{
                if(s.find(it*(-1)) != s.end()){
                    ans = max(ans, it*(-1));
                }
                
            }
        }

        return ans;
    }
};