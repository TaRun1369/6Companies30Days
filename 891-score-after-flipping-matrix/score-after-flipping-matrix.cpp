class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i= 0;i<n;i++){
            int maxval = pow(2,m) - 1;
            int val = 0;
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1)
                val += pow(2,m-j-1);
            }
            // cout<<"val"<<val<<endl;
            if(val > maxval - val){
                // ans += val;
            }
            else{ 
                // ans += (maxval - val);
                // cout<<"firszt i - "<<i<<endl;
                  for(int j = 0;j<m;j++){
                grid[i][j] = !grid[i][j];
                }  
            }
        }

        

         for(int i= 0;i<m;i++){
            int maxval = n;
            int val = 0;
            for(int j = 0;j<n;j++){
                if(grid[j][i] == 1)
                val++;
            }

            if(val > maxval - val){
                ans += val*(pow(2,m-i - 1));
            }
            else{ 
                // cout<<"second  - "<<i<<endl;
                ans += (maxval - val)*(pow(2,m-i - 1));
                  for(int j = 0;j<n;j++){
                grid[j][i] = !grid[j][i];
                }  
            }
        }
        return ans;
    }
};