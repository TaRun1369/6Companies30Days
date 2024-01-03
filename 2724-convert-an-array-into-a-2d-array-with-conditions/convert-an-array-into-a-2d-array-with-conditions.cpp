class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // vector<vector<int>> s;
        // set<int> temp;
        // // for(auto it : nums){
        // //     if(temp.find(it) != temp.end() ){
        // //         vector<int> t (temp.begin(),temp.end());
        // //         s.push_back(t);
        // //         temp.clear();
        // //     }
        // //     else{
        // //         temp.insert(it);
        // //     }
        // // }

        // return s;

                // \U0001f5fa️ Count the frequency of each element
        unordered_map<int, int> m;
        for(auto x : nums) {
            m[x]++;
        }

        // \U0001f4c8 Find the maximum frequency
        int maxi = INT_MIN;
        for(auto x : m) {
            maxi = max(maxi, x.second);
        }

        // \U0001f9e9 Create the 2D array
        vector<vector<int>> ans;
        for(int i = 1; i <= maxi; i++) {
            vector<int> temp;
            for(auto x : m) {
                if(x.second >= i) {
                    temp.push_back(x.first);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;

    }
};