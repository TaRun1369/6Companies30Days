// #include <bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     Node* links[2];// 0 and 1
//     bool containsKey(int bit){ // to check if bit exist or not
//         return links[bit]!=NULL; 
//     }

//      void put(int bit,Node* node){

//         links[bit] = node;
//      }

//      Node* get(int bit){
//         return links[bit];
//      }

// };

// class Trie{
//     private:
//     Node* root;
//     public:
//     Trie(){
//         root = new Node();
//     }
//     void insert(int num){
//         Node* node = root;
//         for(int i = 31;i>= 0;i--){
//             int bit = (num >> i)&1;
//             if(!node->containsKey(bit)){
//                 node->put(bit, new Node());
//             }
//             node = node->get(bit);
//         }
//     }
    
//      int getmax(int x){
//         // get maximum xor value when xor with x 

//         Node* node = root;
//         int maxNum = 0;
//         for(int i = 31;i>=0;i--){
//             int bit = (x>>i)&1;
//             if(node->containsKey(1 -bit)){
//                 maxNum |= (1 << i);
//                 node = node->get(1-bit);
//             }
//             else{
//                 node = node->get(bit);
//             }
//         }
//         return maxNum;
//      }
// };

// // any xor problem with trie can be done using this


// class Solution {
// public:
//     static bool cmp(vector<int>&a,vector<int> &b){
//         return a[1] < b[1];
//     }
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         map<vector<int>,int> mp;
//         for(int i = 0;i<queries.size();i++){
//             mp[queries[i]] = i;
//         }
//         sort(queries.begin(),queries.end(),cmp);
//         int curr = 0;
//         vector<int>ans(queries.size(),-1);
//         Trie t;
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int q = 0;
//         for(auto it : queries){
//             if(nums[0] > it[1]){ ans[mp[it]] = -1;continue;}
//             int lb = lower_bound(nums.begin(),nums.end(),it[1]) - nums.begin();
//             for(int i = curr;i<=min(lb,n-1);i++){
//                 t.insert(nums[i]);
//             }
//             curr = min(lb,n-1);
//             ans[mp[it]] = (t.getmax(it[0]));
            
//         }
//         return ans;
//     }
// };
class Node {
public:
    Node* links[2]; // 0 and 1
    Node() {
        links[0] = links[1] = nullptr;
    }
    bool containsKey(int bit) { // to check if bit exist or not
        return links[bit] != nullptr;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getmax(int x) {
        // get maximum xor value when xor with x 
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> offlineQueries;
        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({queries[i][0], queries[i][1], i});
        }
        sort(offlineQueries.begin(), offlineQueries.end(), cmp);
        sort(nums.begin(), nums.end());

        vector<int> ans(queries.size(), -1);
        Trie t;
        int j = 0;
        for (auto& q : offlineQueries) {
            while (j < nums.size() && nums[j] <= q[1]) {
                t.insert(nums[j]);
                j++;
            }
            if (j != 0) {
                ans[q[2]] = t.getmax(q[0]);
            }
        }
        return ans;
    }
};
