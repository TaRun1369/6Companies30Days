// // class Solution {
// // public:
// //     bool recur(long long one,long long two,long long three,long long four,vector<int> &ms,int ind){
        

// //         if(ind < 0){
// //             if(one + two + three + four == 0) return true;
// //             else return false;
// //         }

// //         bool o = false,t = false,th = false,f = false;
// //         if(one - ms[ind] >= 0){
// //             // cout<<"one"<<endl;
// //             o = recur(one - ms[ind],two,three,four,ms,ind-1);
// //         }
// //          if(two - ms[ind] >= 0){
// //             // cout<<"two"<<endl;
// //             t = recur(one,two - ms[ind],three,four,ms,ind-1);
// //         }
// //          if(three - ms[ind] >= 0){
// //             // cout<<"3"<<endl;
// //             th = recur(one ,two,three - ms[ind],four,ms,ind-1);
// //         }
// //          if(four - ms[ind] >= 0){
// //             // cout<<"4"<<endl;
// //             f = recur(one,two,three,four  - ms[ind],ms,ind-1);
// //         }
// //         // else return false;

// //         return o || t || th || f;

// //     }
// //     bool makesquare(vector<int>& ms) {
// //         int n = ms.size();
// //         long long sum = accumulate(ms.begin(),ms.end(),0);
// //         sort(ms.rbegin(),ms.rend());
// //         if(sum % 4 != 0){
// //             return false;
// //         }
// //         else{
// //             sum/=4;
// //             // cout<<"sum - "<<sum<<endl;
// //             return recur(sum,sum,sum,sum,ms,n-1);
// //         }

// //     }
// // };

// class Solution {
// public:
//     bool recur(long long one, long long two, long long three, long long four, vector<int> &ms, int ind) {
//         if (one < 0 || two < 0 || three < 0 || four < 0)
//             return false;
//         if (ind < 0)
//             return one == 0 && two == 0 && three == 0 && four == 0;

//         return recur(one - ms[ind], two, three, four, ms, ind - 1) ||
//                recur(one, two - ms[ind], three, four, ms, ind - 1) ||
//                recur(one, two, three - ms[ind], four, ms, ind - 1) ||
//                recur(one, two, three, four - ms[ind], ms, ind - 1);
//     }

//     bool makesquare(vector<int>& ms) {
//         int n = ms.size();
//         if (n < 4) return false; // If less than 4 sticks, cannot form a square.
//         long long sum = accumulate(ms.begin(), ms.end(), 0);
//         if (sum % 4 != 0)
//             return false;

//         long long side = sum / 4;
//         sort(ms.rbegin(), ms.rend());

//         return recur(side, side, side, side, ms, n - 1);
//     }
// };


class Solution {
public:
    bool dfs(vector<int>& matchsticks, int sides[], int target, int index) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > target) continue; // Pruning
            
            int j = i;
            while (--j >= 0) {
                if (sides[i] == sides[j]) break; // Pruning, avoid duplicate calculations
            }
            if (j != -1) continue;
            
            sides[i] += matchsticks[index];
            if (dfs(matchsticks, sides, target, index + 1)) return true;
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        int sides[4] = {0};
        return dfs(matchsticks, sides, sum / 4, 0);
    }
};
