class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        for(auto it : points) cout<<it[0]<<","<<it[1]<<"   ";
        cout<<endl;
        vector<int> prev = points[0];
        int n = points.size();
        int ans = 0;
        for(int i = 1;i<n;i++){
            // cout<<"i - "<<i<<" prev "<<prev[0]<<" "<<prev[1]<<" curr "<<points[i][0]<<" "<<points[i][1]<<endl;
            if(points[i][0] >= prev[0] && points[i][0] <= prev[1]){
                prev[0] = points[i][0];
                prev[1] = min(prev[1],points[i][1]);
            }
            else{
                ans++;
                prev = points[i];
            }
        }
        return ans+1;
    }
};