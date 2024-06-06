// // class Solution {
// // public:
// //     bool isNStraightHand(vector<int>& hand, int gs) {
// //         if(hand.size() % gs != 0) return false;

// //         unordered_map<int,int>mp;
// //         for(auto it : hand) mp[it]++;
// //         for(auto &it : mp){
// //             // mp[it.first]--;
// //             it.second--;
// //             if(it.second == 0) mp.erase(it.first);
// //             for(int i = 1;i<gs;i++){
// //                 if(mp.find(it.first + i) == mp.end()) return false;
// //                 else{
// //                     mp[it.first+1]--;
// //                     if(mp[it.first+1] == 0) mp.erase(it.first+1);
// //                 }
// //             }
// //         }
// //         return true;
// //     }
// // };

// #include <vector>
// #include <map>
// #include <unordered_map>
// using namespace std;

// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int gs) {
//         if(hand.size() % gs != 0) return false;

//         map<int, int> mp;
//         for(auto it : hand) mp[it]++;

//         for(auto it = mp.begin(); it != mp.end(); ) {
//             if(it->second > 0) {
//                 int start = it->first;
//                 for(int i = 0; i < gs; i++) {
//                     if(mp[start + i] <= 0) return false;
//                     mp[start + i]--;
//                 }
//             }
//             if(it->second == 0) {
//                 it = mp.erase(it);
//             } else {
//                 ++it;
//             }
//         }
//         return true;
//     }
// };

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs != 0) return false;

        map<int, int> mp;
        for(auto it : hand) mp[it]++;

        while(!mp.empty()) {
            int start = mp.begin()->first;
            for(int i = 0; i < gs; ++i) {
                if(mp[start + i] == 0) return false;
                if(--mp[start + i] == 0) {
                    mp.erase(start + i);
                }
            }
        }
        return true;
    }
};
