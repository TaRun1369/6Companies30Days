class Solution {
public:
    unordered_map<int,queue<int>> mp;
    
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push(i);
        }
        
    }
    
    int pick(int target) {
        // queue<int> q =mp[target];
        
        int f = mp[target].front();
        mp[target].pop();
        mp[target].push(f);
        return f;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */