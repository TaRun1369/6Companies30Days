class Solution {
public:
    int incremovableSubarrayCount(vector<int>& a) {
        int n = a.size();
        int i=0;
        for(;i<n-1;i++){
            if(a[i+1]<=a[i]) break;
        }
        int j=n-1;
        for(;j>0;j--){
            if(a[j-1]>=a[j]) break;
        }
        int ans=0;
            while(i>=0){
                int u = upper_bound(a.begin()+j, a.end(), a[i])-a.begin();
                ans += n-u+1;
                i--;
            }
        if(ans<(n*(n+1))/2){
            ans += n-j+1;
        }
        return ans;
    }
};