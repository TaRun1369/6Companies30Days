class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long currmaxreachable = 0;
        int ans = 0;
        int i = 0;
        while(i < nums.size()){
            if(currmaxreachable > n) break;
            if(nums[i] <= currmaxreachable + 1){
                currmaxreachable += nums[i];
                i++;
                // continue;
            }
            else{
                int l = currmaxreachable;
                currmaxreachable+= l + 1;
                // currmaxreachable += it;
                ans++;
            }
        }
                cout<<currmaxreachable<<endl;

        // int last =currmaxreachable+ 1 ;
        while(currmaxreachable < n){
            int last =currmaxreachable+ 1 ;
            currmaxreachable += (last);
            ans++;
            // last++;
        }
        cout<<currmaxreachable<<endl;
        return ans;
    }
};