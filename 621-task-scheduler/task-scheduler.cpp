// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> hash(26,0);
//         for(auto it : tasks){
//             hash[it - 'A']++;
//         }

//         priority_queue<pair<int,char>> pq;
//         for(int i = 0;i<26;i++){
//             if(hash[i] != 0){
//                 pq.push({hash[i],char(i+'A')});
//             }
//         }


//         int curr = 0;
//         vector<vector<int>> v;
//         while(!pq.empty()){
//             pair<int,char> p = pq.top();
//             pq.pop();

//             curr++;
//             p.first--;

//             for(auto it : v){
//                 it[2]--;
//                 if(it[2] == 0){
//                     pq.push({it[1],char(it[0] + 'A')});
//                 }
//             }
//             if(p.first > 0)
//             v.push_back({p.second-'A',p.first,n});

//         }
//         return curr;
//     }
// };



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for(auto it : tasks){
            hash[it - 'A']++;
        }

        priority_queue<int> pq;
        for(int i = 0; i < 26; i++){
            if(hash[i] != 0){
                pq.push(hash[i]);
            }
        }

        int curr = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0; i <= n; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }
            for(auto t : temp){
                if(t > 0){
                    pq.push(t);
                }
            }
            curr += pq.empty() ? temp.size() : n + 1;
        }
        return curr;
    }
};
