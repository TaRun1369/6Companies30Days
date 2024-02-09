class Solution {
public:
    int numSquares(int n) {
        vector<int>prev(n+1,1e9);
        prev[0]=0;
        for(int index=1;index<=n;index++)
        {
            
            for(int target=0;target<=n;target++)
            {
                int nottake=prev[target];
                int take=INT_MAX;
                if(index*index<=target)
                {
                    take=1+prev[target-(index*index)];
                }
                prev[target]=min(take,nottake);
            }
        }
        if(prev[n]>=1e9)
        {
            return 1;
        }
        return prev[n];
    }
};