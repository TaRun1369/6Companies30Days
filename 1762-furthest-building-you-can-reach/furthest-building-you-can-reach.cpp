class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if(n == 1)
            return 0;
        priority_queue<int> pq;
        int i = 0;
        for (; i < n - 1; i++) {
            if (heights[i + 1] <= heights[i])
                continue;
            int diff = heights[i + 1] - heights[i];
            if (bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            } else if (ladders > 0) {
                if (!pq.empty()) {
                    int past_bricks = pq.top();
                    if (past_bricks > diff) {
                        bricks += past_bricks;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);                        
                    }
                }
                ladders--;
            } else
                break;
        }
        return i;
    }
};