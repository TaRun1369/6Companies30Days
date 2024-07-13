// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
//         int n = p.size();
//         vector<int> fh(n,0);
//         map<int,int> mp;
//         for(int i = 0;i<n;i++){
//             mp[p[i]] = i;
//         }
//         stack<pair<char,pair<int,int>>> st;

//         for(auto it : mp){
//             if(st.empty()){
//                 st.push({d[it.second],{h[it.second],it.second}});
//             }
//             else{
//                 char currdirec = d[it.second];
//                 char tdirec = st.top().first;
//                 if(currdirec == 'R' && tdirec == 'L'){
//                     int currhealth = h[it.second];
//                     int thealth = st.top().second.first;
//                     while(true){
//                             if(currhealth > thealth){
//                                 currhealth--;
//                             }
//                             else if(currhealth < thealth){
//                                 st.push({tdirec,{ st.top().second.first - 1,st.top().second.second}});
//                             }
//                             else{
//                                 st.pop();
//                                 break;
//                             }
//                              st.pop();
//                     }
//                 }
//                 else{
//                     st.push({d[it.second],{h[it.second],it.second}});
//                 }
//             }
//         }
//         while(!st.empty()){
//             fh[st.top().second.second] = st.top().second.first;
//         }
//         vector<int>ans;
//         for(auto it : fh){
//             if(it > 0) ans.push_back(it);
//         }
//         return ans;

//     }
// };
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> finalHealth(n, 0);
        
        // Pair positions with their indices and sort based on positions
        vector<pair<int, int>> pos_index;
        for (int i = 0; i < n; ++i) {
            pos_index.push_back({positions[i], i});
        }
        sort(pos_index.begin(), pos_index.end());

        stack<pair<int, int>> st;  // Stack to hold index and health of robots

        for (int i = 0; i < n; ++i) {
            int idx = pos_index[i].second;
            char direction = directions[idx];
            int health = healths[idx];

            if (direction == 'R') {
                // Push right-moving robots onto the stack
                st.push({idx, health});
            } else {
                // Process left-moving robots
                while (!st.empty() && directions[st.top().first] == 'R') {
                    int rightIdx = st.top().first;
                    int rightHealth = st.top().second;
                    
                    if (health > rightHealth) {
                        // Left robot survives, right robot dies
                        st.pop();
                        health -= 1;
                    } else if (health < rightHealth) {
                        // Right robot survives, left robot dies
                        st.top().second -= 1;
                        health = 0;
                        break;
                    } else {
                        // Both robots have the same health and die
                        st.pop();
                        health = 0;
                        break;
                    }
                }
                if (health > 0) {
                    // If the left-moving robot still has health, it survives
                    finalHealth[idx] = health;
                }
            }
        }

        // Add remaining right-moving robots to finalHealth
        while (!st.empty()) {
            finalHealth[st.top().first] = st.top().second;
            st.pop();
        }

        // Collect the healths of the survived robots
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (finalHealth[i] > 0) {
                result.push_back(finalHealth[i]);
            }
        }

        return result;
    }
};
