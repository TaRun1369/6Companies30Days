class Solution {
public:
    long long M = 1e9 + 7;
    int n,m;
    int NoOfApples[55][55];
    int dp[55][55][10];
    int recur(int k,int i,int j){
        if(NoOfApples[i][j] < k) return 0;
        if(k == 1){
            if(NoOfApples[i][j] >= 1) return 1;
            else return 0;
        }
        int ans = 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        for(int h = i+1;h<m;h++){
            int lowerslice = NoOfApples[h][j];

            int upperslice = NoOfApples[i][j] - lowerslice;
            if(upperslice >= 1 && lowerslice >= k-1){
                ans = (ans%M + recur(k-1,h,j)%M)%M;
            }
        }

        for(int v = j + 1;v<n;v++){
            int rightslice = NoOfApples[i][v];
            int leftslice = NoOfApples[i][j] - rightslice;
            
            if(leftslice >= 1 && rightslice >= k-1){
                ans = (ans%M +  recur(k-1,i,v)%M)%M;
            }

        }
        return dp[i][j][k] = ans%M;
    }
    int ways(vector<string>& pizza, int k) {
         m = pizza.size();
         n = pizza[0].size();

        // vector<vector<int>> NoOfApples(n+1,vector<int>(m+1,0));
        memset( NoOfApples,0,sizeof(NoOfApples));
         memset( dp,-1,sizeof(dp));
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                NoOfApples[i][j] = NoOfApples[i][j+1];
                for(int l = i;l<m;l++){
                    if(pizza[l][j] == 'A')
                    NoOfApples[i][j]++;
                }
            }
        }
        return recur(k,0,0);
    }
};