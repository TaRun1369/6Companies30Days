class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& trip, vector<int>& t) {
        set<int> ind;
        int c = 0;
        for(auto it : trip){
                bool fl = false;
                if(it[0] <= t[0] && it[1] <= t[1] && it[2] <= t[2]) fl = true;
                if(fl == true) ind.insert(c);
                c++;
        }
        vector<int> final(3,INT_MIN);
        for(auto it : ind){
            final[0] = max(trip[it][0],final[0]);
            final[1] = max(trip[it][1],final[1]);
            final[2] = max(trip[it][2],final[2]);
        }
        if(final == t) return true;
        return false;
    }
};