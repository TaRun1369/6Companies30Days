class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 1 2 4 1 1
        
        // 1 3 7 8 9
       
        // 9 7 3 2 1
        int n = nums.size();
         if(k == 1 && n >=2) return true;
        map<int,int> s;
        int pref = 0;
        for(int i = 0;i<n;i++){
            pref += nums[i];
            if((pref > k && s.find(pref%k) != s.end())  ){
                if(i - s[pref%k]  >= 2) return true;
               
            }
             else if ((pref%k == 0 && i >= 1)) return true;
             else if(s.find(pref) != s.end()){
                    if(i - s[pref]  >= 2) return true;

             }
             if(s.find(pref%k) == s.end())
            s[pref%k] = i;
        }
        return false;
    }
};