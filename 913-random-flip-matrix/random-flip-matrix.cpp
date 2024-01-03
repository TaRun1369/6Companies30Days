class Solution {
public:
    int M;
    int N;
    set<pair<int, int>> s;
    Solution(int m, int n) {
        M = m;
        N= n;

    }
    
    vector<int> flip() {
        int x = rand()%M;
        int y = rand()%N;
        if(s.find({x, y})!=s.end()){
            return flip();
        }
        else{
            s.insert({x, y});
            return {x, y};
        }
    }
    
    void reset() {
        s.clear();
    }
};

