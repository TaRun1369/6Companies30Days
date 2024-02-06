class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto it : strs){
            string sortedStr = it;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string

            mp[sortedStr].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
