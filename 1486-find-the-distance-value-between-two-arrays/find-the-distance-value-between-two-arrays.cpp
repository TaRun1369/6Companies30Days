class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        unordered_set<int> s(arr2.begin(),arr2.end());
        int ans = 0;
        for(auto it : arr1){
            int flag = 1;
            for(int i = it - d;i <= (it + d);i++){
                if(s.find(i) != s.end()){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) ans++;
            
        }
        return ans;

    }
};