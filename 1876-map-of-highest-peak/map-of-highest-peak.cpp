class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;int m = isWater.size();
        int n = isWater[0].size();
         vector<vector<int>> visited(m,vector<int>(n,0));
         vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

       


            vector<int> di = {0,1,0,-1},dj = {-1,0,1,0};

        while(!q.empty()){
            auto top = q.front();
            q.pop();
           
            for(int i = 0;i<4;i++){
                int adi = top.first + di[i];
                int adj = top.second + dj[i];

                if(adi >= 0 && adj >= 0 && adi < m && adj < n && !visited[adi][adj] && isWater[adi][adj] == 0){
                    q.push({adi,adj});
                     ans[adi][adj] = ans[top.first][top.second]+1;
            visited[adi][adj] = 1; 
                    
                }
            }   
            
        }
        return ans;
    }
};