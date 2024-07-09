class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currtime = 0;
        
        double ans = 0; 
        for(auto it : customers){
            int wait = 0;
            if(currtime - it[0] > 0) wait = currtime - it[0];
            currtime = max(currtime,it[0]);
            
            ans += wait + it[1];
            currtime += it[1];
            // cout<<wait<<endl;
            
        }
        double a = ans/(double(customers.size()));
        return a;
    }
};