class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int n = arr.size();
        sort(arr.begin(),arr.end());
        int count = 1;
        int prev = arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i] == prev){
                count++;
            }
            else{
                
               
                pq.push({count,prev});
                 count=1;
                prev = arr[i];
            }
        }
        pq.push({count,prev});
        int ans = pq.size();
        while(!pq.empty() || k > 0){
            pair<int,int> pp = pq.top();
            pq.pop();
            cout<<" count "<<pp.first<<endl;
            if(pp.first <= k){
                k-=pp.first;
                ans--;
            }
            else{
                break;
            }
        }
    return ans;
    }
};