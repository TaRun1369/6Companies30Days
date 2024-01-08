class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int  n = img[0].size();
        vector<vector<int>>  ans(m,vector<int> (n,0));
        vector<int> di = {-1,0,1,1,1,0,-1,-1,0},dj = {1,1,1,0,-1,-1,-1,0,0};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int sum = 0,count = 0;
                for(int k = 0;k<9;k++){
                    if(i+di[k] >= 0 && i+di[k] < m && j+dj[k] >= 0 && j+dj[k] <n){
                    sum += img[i + di[k]][j + dj[k]];
                    count++;
                    }

                }
                ans[i][j] = sum/count;
            }
        }

        return ans;
    }
};