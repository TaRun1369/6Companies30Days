bool helper(vector<int> &a, vector<int> &b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    
    if(a[2] != b[2])
        return a[2] < b[2];
    
    return a[2] ? a[1] < b[1] : a[1] > b[1];
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        map<int, int> mp;
        vector<vector<int>> v, ans;
        
        // 0 -> start, 1 -> end
        for(auto &i : buildings)
            v.push_back({i[0], i[2], 0}), v.push_back({i[1], i[2], 1});
        
        mp[0]++;
        sort(v.begin(), v.end(), helper);
        
        for(auto &i : v)
        {
            auto it = mp.end();
            int prev_mx = (--it)->first;
            
            if(i[2] == 0) // start of new building insert the height
                mp[i[1]]++;
            else if(!(--mp[i[1]])) // end of prev building erase the height
                mp.erase(i[1]);
            
            it = mp.end();
            int new_mx = (--it)->first;
            
            if(prev_mx != new_mx)
                ans.push_back({i[0], new_mx});
        }
        
        return ans;
    }
};