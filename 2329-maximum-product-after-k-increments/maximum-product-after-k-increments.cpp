class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : nums){
            pq.push(it);
        }

        while(!pq.empty() && k > 0){
            int l = pq.top();
            pq.pop();
            l++;
            pq.push(l);
            k--;
        }
        int m = 1e9 + 7;
        long long ans = 1;
        while(!pq.empty()){
            ans *= (pq.top()%m);
            ans%=m;
            pq.pop();
        }
        return int(ans%m);
    }
};