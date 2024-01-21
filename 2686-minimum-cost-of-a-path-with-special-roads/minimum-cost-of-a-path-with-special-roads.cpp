class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // use dijkstras algorithm
        int sx = start[0], sy = start[1];
        int tx = target[0], ty = target[1];
        
        using ll = long long;
        using pipii = pair<ll,pair<int,int>>;
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        
        ll INF = 1e12;
        
        map<pair<int,int>,ll> distance;
        
        auto dist = [&](int x, int y) {
            if(not distance.count({x, y})) distance[{x,y}] = INF;
            return distance[{x,y}];
        };
        
        pq.push({0, {sx, sy}});
        distance[{sx, sy}] = 0;
        
        while(not pq.empty()) {
            ll d = pq.top().first;
            
            auto [cx, cy] = pq.top().second;
            
            pq.pop();
            
            if(cx == tx and cy == ty) return d;
            
            // directly go to target
            ll direct = d + abs(cx-tx) + abs(cy-ty);
            
            pq.push({direct, {tx, ty}});
            
            
            // take some road
            for(vector<int>& road : specialRoads) {
                int fromx = road[0], fromy = road[1];
                int tox  = road[2], toy = road[3];
                ll cost = road[4];
                
                ll val = d + cost + abs(cx-fromx) + abs(cy-fromy);
                    
                if(dist(tox, toy) > val) {
                    distance[{tox, toy}] = val;
                    pq.push({val, {tox, toy}});
                }
            }
        }
        
        return -1;
    }
};