class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));

        for(int i = 0;i<n;i++) mat[i][i] = 0;

        for(auto it : edges){
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
        }

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                   if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX) continue;
                   mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]); 
                }
            }
        }
        

        int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (mat[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};