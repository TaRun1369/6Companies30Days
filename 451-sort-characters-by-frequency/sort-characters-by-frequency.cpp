class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v(150);
        for (int i = 0; i < 150; i++) {
            v[i] = {0, i};
        }
        for (char c : s) {
            v[c].first++;
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string ans = "";
        for (auto it : v) {
            int count = it.first;
            char character = it.second;
            for (int i = 0; i < count; i++) {
                ans += character;
            }
        }
        for(auto it : v){
            cout<<it.first<<" "<<it.second<<endl;
        }

        return ans;
    }
};
