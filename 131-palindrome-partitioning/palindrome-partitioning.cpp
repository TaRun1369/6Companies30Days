// // class Solution {
// // public:
// //     bool ispalin(string s){
// //         string t = s;
// //         reverse(s.begin(),s.end());
// //         if(t == s) return true;
// //         return false;
// //     }
// //     void recur(string s,int ind,int prev,vector<vector<string>> &ans,vector<string> &ann){
// //         if(ind == 0){
// //             ans.push_back(ann);
// //             return;
// //         }

// //         for(int i = ind ;ind >= 0;ind--){
// //             if(ispalin(s.substr(ind,ind - i + 1))){
// //                 ann.push_back(s.substr(ind,ind - i + 1 ));
// //                 recur(s,i,ind-1,ans,ann);
// //                 ans.pop_back();
// //             }
// //             // recur(s,i,prev,ans,ann);
// //         }

// //     }
// //     vector<vector<string>> partition(string s) {
// //         vector<vector<string>>ans;
// //         int n = s.size();
// //         vector<string> ann;
// //         recur(s,n-1,n-1,ans,ann);
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     bool ispalin(string s) {
//         string t = s;
//         reverse(s.begin(), s.end());
//         return t == s;
//     }

//     void recur(string s, int ind, vector<vector<string>> &ans, vector<string> &ann) {
//         if (ind < 0) {
//             reverse(ann.begin(),ann.end());
//             ans.push_back(ann);
//             return;
//         }

//         for (int i = ind; i >= 0; i--) {
//             if (ispalin(s.substr(i, ind - i + 1))) {
//                 ann.push_back(s.substr(i, ind - i + 1));
//                 recur(s, i - 1, ans, ann);
//                 ann.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> ann;
//         int n = s.size();
//         recur(s, n - 1, ans, ann);

//         return ans;
//     }
// };

class Solution {
public:
    bool ispalin(string s){
        string t = s;
        reverse(s.begin(), s.end());
        return t == s;
    }

    void recur(string s, int start, vector<vector<string>> &ans, vector<string> &current) {
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (ispalin(s.substr(start, end - start + 1))) {
                current.push_back(s.substr(start, end - start + 1));
                recur(s, end + 1, ans, current);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        recur(s, 0, ans, current);
        return ans;
    }
};
