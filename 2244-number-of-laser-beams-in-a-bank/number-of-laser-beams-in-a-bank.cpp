class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;

        int prev = 0;
        for(auto it : bank){
            int count1 = 0;
            for(auto is : it){
                if(is == '1') count1++;
            }
            if(count1 == 0) continue;

            ans += (prev * count1);
            prev = count1;
        }

        return ans;
    }
};