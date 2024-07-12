class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> hashmap(26);
        int n = s.size();
        for(int i = 0;i<26;i++){
            hashmap[i].push_back(-1);
        }

        for(int i = 0;i<n;i++){
            hashmap[s[i] - 'A'].push_back(i);
        }

        for(int i = 0;i<26;i++){
            hashmap[i].push_back(n);
        }

        long long count = 0;
        for(int i = 0;i<26;i++){
            for(int j = 1;j<hashmap[i].size() - 1;j++){
                count += ((hashmap[i][j] - hashmap[i][j-1]) * (hashmap[i][j+1] - hashmap[i][j]));
            }
        }
        return count;


    }
};