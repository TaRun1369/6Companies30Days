class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0,n = prices.size(),mini = INT_MAX;
        for(int i = 0;i<n;i++){
            cout<<"mini - "<<mini<<endl;
            mini = min(mini,prices[i]);
            cout<<"mini - "<<mini<<endl;
            if(i+1 < n && prices[i+1] < prices[i] && prices[i] > mini){
                maxi += prices[i] - mini;
                mini = INT_MAX;
            }

        }
        if(mini != INT_MAX){
            maxi += prices[n-1] - mini;
        }
        return maxi;
    }

};