class Solution {
public:
    int leastBricks(vector<vector<int>>&wall) {
        // if(wall[0].size() == 1) return wall.size();
        // // int width = accumulate(wall[0].begin(),wall[0].end(),0);
        
        // unordered_map<int,int> mp;
        //    int maxi = 0;
        // // for(int i = 2;i<1+width;i++){
        // //     mp[i] = 0;
        // // }
        // for(auto it : wall){
        //     int pre = 0;
        //     for(int k = 0;k<it.size() - 1;k++){
        //         pre += it[k];
        //         mp[pre]++;
        //         maxi  = max(maxi,mp[pre]);
        //     }

        // }       
        // return wall.size() - maxi;
        int wall_height = wall.size();

    int ans = 0;

    unordered_map<int,int> s;

    for(int i=0; i<wall_height; i++)
    {
        int total_width = 0;
        for(int k=0; k<wall[i].size()-1; k++)
        {
             total_width = total_width + wall[i][k];
             s[total_width]++;

             ans = max(ans, s[total_width]);
        } 
    }

    return wall_height - ans;
    }
};