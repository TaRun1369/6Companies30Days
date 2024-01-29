class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long sum = mass;
        for(auto it : a){
            if(it > sum){
                return false;
            }
            sum += it;
        }
        return true;
    }
};