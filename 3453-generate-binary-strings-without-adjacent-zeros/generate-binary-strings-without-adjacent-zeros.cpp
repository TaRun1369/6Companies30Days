// class Solution {
// public:

//     void recur(int n,int prev,string &s,vector<string> &ans){
//         if(n == 0){
//             ans.push_back(s);
//         }

//         if(prev == 0){
//             s.push_back('1');
//             recur(n-1,1,s,ans);
//             s.pop_back();

//         }
//             s.push_back('0');
//              recur(n-1,0,s,ans);
//              s.pop_back();
            
//     }
//     vector<string> validStrings(int n) {
//         vector<string> ans;
//         string s = "";
//         recur( n, -1,s,ans);
//         return ans; 
//     }
// };
class Solution {
public:
    void recur(int n, int prev, string &s, vector<string> &ans) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }

        if (prev == 1 || prev == -1) {
            s.push_back('0');
            recur(n - 1, 0, s, ans);
            s.pop_back();
        }

        s.push_back('1');
        recur(n - 1, 1, s, ans);
        s.pop_back();
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        recur(n, -1, s, ans);
        return ans;
    }
};
