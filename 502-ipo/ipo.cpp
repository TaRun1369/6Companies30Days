// struct cmp {
//   bool operator()(
//     pair<int, int>& a,
//     pair<int, int>& b)
//   {
//     if(a.first == b.first) return a.first + a.second < a.first + b.second;
//      return a.first < b.first;
//   }
// };

// class Solution {
// public:
// //             auto compare = [](int lhs, int rhs){
                
// //                 return lhs < rhs;
// // };

//     int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
//         if(*min_element(c.begin(),c.end()) > w) return 0;
//         if(k >= p.size()) return w + accumulate(p.begin(),p.end(),0);

//         priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
//         int n = p.size();
// int ans = w;
//         for(int i = 0;i<n;i++){
//             pq.push({p[i] - c[i],c[i]});
//         }

//                 //  while(!pq.empty()){
//                 // cout<<pq.top().first<<" "<<pq.top().second<<endl;
//                 // pq.pop();
//                 // }


//             while(!pq.empty() && k >0){
//                 // cout<<pq.top().first<<" "<<pq.top().second<<endl;
//                 vector<pair<int,int>>v;
//                 // auto tp = pq.top();
//                 // pq.pop();
//                 while(pq.top().second > w || pq.top().first < 0){
//                     // cout<<"yaha"<<endl;
//                     v.push_back(pq.top());
//                     pq.pop();
//                 }
//                 // cout<<pq.size()<<endl;
//                 if(pq.empty()){ break;}
//                 auto tp = pq.top();
//                 pq.pop();
//                 ans += (tp.first + tp.second);
//                 // cout<<ans<<endl;
//                 w += tp.first;
//                 k--;
//                 // if(v.size() != pq.size())
//                 for(auto it : v) pq.push(it);

//             }

//         return ans;

//     }
// };

#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Number of projects
        int n = profits.size();

        // Create a vector of pairs (capital, profit)
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Sort the projects based on capital required (ascending order)
        sort(projects.begin(), projects.end());

        // Max-heap to store profits of the projects we can afford
        priority_queue<int> maxHeap;
        int index = 0;

        // Iterate k times to select up to k projects
        for (int i = 0; i < k; ++i) {
            // Push all projects we can afford into the max-heap
            while (index < n && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                ++index;
            }

            // If we can't afford any more projects, break
            if (maxHeap.empty()) {
                break;
            }

            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
