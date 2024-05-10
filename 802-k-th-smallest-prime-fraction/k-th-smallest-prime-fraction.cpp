class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n= arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                double d = arr[i]/(double)arr[j];
                pq.push({d,{i,j}});
            }
        }
k-=1;
while(k--){
    cout<<pq.top().first<<endl;
    pq.pop();
}

    return {arr[pq.top().second.first],arr[pq.top().second.second]};

    }
};