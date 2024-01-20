class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rC, int cC) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                int dist = abs(rC - i) + abs(cC - j);
                pq.push({dist,{i,j}});
            }
        }
        vector<vector<int>> v;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            vector<int> t = {top.second.first,top.second.second};
            v.push_back(t);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};