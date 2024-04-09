class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int kitnebaar = t[k];
        int n = t.size(),ans =0;
        for(int i = 0;i<n;i++){
            if(i <= k){
                ans += min(t[i],t[k]);
            }
            else{
                ans += min(t[i] , t[k] -1);
            }
        }
        return ans;
    }
};