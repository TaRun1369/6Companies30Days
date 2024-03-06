class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr = 0;
        for(int i = 1;i<= n;i++){
            if(curr >= target.size() ) break;
            if(target[curr] == i){
                ans.push_back("Push");
                curr++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
        }
        return ans;
    }
};