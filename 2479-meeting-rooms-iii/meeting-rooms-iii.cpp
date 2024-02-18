// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(),meetings.end());
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
//         priority_queue<int,vector<int>,greater<int>> p;
//         for(int i = 0;i<n;i++){
//             p.push(i);
//         }

//         vector<int> counter(n,0);
        
//         // vector<int> visited(n,0);
//         // int k = n;
//         int currtime = meetings[0][0];
//         for(auto it : meetings){
//             cout<<" curr log "<<it[0]<<" - "<<it[1]<<endl;
//             if(!p.empty()){
               
//                 currtime = it[0];
//                 cout<<"currytime - "<<currtime<<endl;
//                 while(!pq.empty()){
//                 auto topp = pq.top();
               
//                 if(topp.first <= currtime){
//                     cout<<"nikla "<<" ";
//                      cout<<"topp - "<<topp.first<<" "<<topp.second<<endl;
//                     pq.pop();
//                     p.push(topp.second);
//                 }
//                 else{
//                     cout<<"nhi nikla "<<" ";
//                      cout<<"topp - "<<topp.first<<" "<<topp.second<<endl;
//                     break;
//                 }
//             }
//              pq.push({it[1],p.top()});
//                 counter[p.top()]++;
//                 p.pop();
//             }else{
//                 pair<int,int> pai = pq.top();
//                 pq.pop();
//                 // pq.push()
//                 pair<int,int> newpair;
//                 currtime = max(pai.first,it[0]); 
//                 cout<<"currytime - "<<currtime<<endl;
//                 cout<<" -size-- "<<pq.size()<<endl;
//                 while(!pq.empty()){

//                 auto topp = pq.top();
//                 // cout<<"topp - "<<topp.first<<" "<<topp.second<<endl;
//                             if(topp.first <= currtime){
//                                 cout<<"nikla "<<" ";
//                                 cout<<"topp - "<<topp.first<<" "<<topp.second<<endl;
//                                 pq.pop();
//                                 p.push(topp.second);
//                             }
//                             else{
//                                 cout<<"nhi nikla "<<" ";
//                                 cout<<"topp - "<<topp.first<<" "<<topp.second<<endl;
//                                 break;
//                             }
//                 }
//                 int diff = it[1]-it[0];
//                 newpair = {currtime + diff ,pai.second};
//                 pq.push(newpair);
//                 counter[pai.second]++;

//             }

//             cout<<"maxi kaun "<<max_element(counter.begin(),counter.end()) - counter.begin()<<endl;
//         }

//         return max_element(counter.begin(),counter.end()) - counter.begin();
//     }
// };

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if(n==1) return 0;
        sort(meetings.begin(),meetings.end());
        priority_queue<long,vector<long>,greater<long> > avRooms;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>> > allRooms;
        for(int i=0;i<n;i++) avRooms.push(i);
        vector<int> count(n,0);
        long t = 0;
        for(int i=0;i<meetings.size();i++)
        {
            while(!allRooms.empty() && allRooms.top().first <= meetings[i][0]){
                auto p = allRooms.top(); allRooms.pop();
                t = p.first;
                int room = p.second;
                avRooms.push(room);
            }
            if(!avRooms.empty()){
                int room = avRooms.top(); avRooms.pop();
                allRooms.push({meetings[i][1],room});
                count[room]++;
                continue;
            }
            else {
                auto p = allRooms.top(); allRooms.pop();
                t = p.first;
                int room = p.second;
                allRooms.push({t+meetings[i][1]-meetings[i][0],room});
                count[room]++;
            }
        }
        int data = INT_MIN;
        int ans;
        for(int i=0;i<n;i++) {
            cout<<count[i]<<" ";
            if(data < count[i]){
                ans = i;
                data = count[i];
            }
        }
        return ans;
    }
};