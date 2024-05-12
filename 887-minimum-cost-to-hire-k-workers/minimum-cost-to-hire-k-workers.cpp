class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double,int>> ratios;
        for(int i = 0;i<n;i++){
            ratios.push_back({(wage[i]/(double)quality[i]),quality[i]});
        }
        sort(ratios.begin(),ratios.end());

        // for(auto it : ratios){
        //     // cout<<it.first<<" "<<it.second<<endl;
        // }
        priority_queue<int> pq;
        int sum = 0;
        for(int i = 0;i<k;i++){
            pq.push(ratios[i].second);
            sum += ratios[i].second;
        }
        double mainratio = ratios[k-1].first;
        double result = mainratio*sum;
        // cout<<"result - "<<result<<" sum  - "<<sum<<endl;
        for(int i = k;i<n;i++){

            mainratio = ratios[i].first;
            pq.push(ratios[i].second);
            sum += ratios[i].second;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
                
            }

            result = min(result,mainratio*sum);
        }
        return result;
        
    }
};