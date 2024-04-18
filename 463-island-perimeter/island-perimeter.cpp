class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]){ //only runs when a land cell is encountered
                int temp = 4; // Ideally, perimeter of 1 grid cell is 4
                if((i+1<grid.size() && grid[i+1][j])) temp--; // check if the grid below is land
                if(j+1<grid[0].size() && grid[i][j+1]) temp--; //check if right grid is land
                if(i-1>=0 && grid[i-1][j]) temp--; //check if land above is a land
                if(j-1>=0 && grid[i][j-1]) temp--; //check if left grid is a land
                res+=temp; //sum up in res
            }
        }
        return res;
    }
};