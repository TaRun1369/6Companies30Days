
class Solution {
public:
    void setIthBit(int &n, int i) {
        n = n | (1 << i);
    }

    void clearIthBit(int &n, int i) {
        n = n & (~(1 << i));
    }

    bool checkIthIsBitSet(int n, int i) {
        return (n & (1 << i)) != 0;
    }

    int recur(vector<string> &arr, int ind, int &mask, unordered_map<int, unordered_map<int, int>> &memo) {
        if (ind >= arr.size()) return 0;
        if (memo[ind].find(mask) != memo[ind].end()) return memo[ind][mask];

        int f = 0;
        // set<char>st;
        // for(auto it : arr[ind]) st.insert(it);
        vector<int> hash(26,0);
        for (auto it : arr[ind]) {
            // cout<<it<<endl;
            
            if (checkIthIsBitSet(mask, it - 'a') || hash[it - 'a'] >=1 ) {
                f = 1;
                break;
            }hash[it - 'a']++;
        }

        int take = INT_MIN;
        if (f == 0) {
            for (auto it : arr[ind]) {
                setIthBit(mask, it - 'a');
            }
            cout<<arr[ind]<<endl;
            take = arr[ind].size() + recur(arr, ind + 1, mask, memo);
            for (auto it : arr[ind]) {
                clearIthBit(mask, it - 'a');
            }
        }

        int nottake = recur(arr, ind + 1, mask, memo);
        // cout<<take<<endl;
        memo[ind][mask] = max(take, nottake);
        return memo[ind][mask];
    }

    int maxLength(vector<string>& arr) {
        int mask = 0;
        unordered_map<int, unordered_map<int, int>> memo;
        return recur(arr, 0, mask, memo);
    }
};
