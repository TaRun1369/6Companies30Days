class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // distfromtarg , speed
        int n = speed.size();
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({target - position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        int nooffleet = 0;
        double currtime = 0.0;
        for(auto it : v){
            if((double)it.first/(double)it.second > currtime){
                nooffleet++;
                currtime = (double)it.first/(double)it.second;
            }
        }
        return nooffleet;
    }
};