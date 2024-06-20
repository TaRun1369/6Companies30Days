class Solution {
public:
    bool ispossible(int currdiff , vector<int> &p,int m){
        // cout<<"diff - "<<currdiff<<endl;
        int start = 0;
        int l = 0;
        m--;
        while(m > 0 && l < p.size()){
            l = lower_bound(p.begin(),p.end(),(p[start] + currdiff)) - p.begin();
            if(l < p.size())
            m--;
            // cout<<l<<" -  "<<m<<endl;
            start = l;
        }

        if(m <= 0) return true;
        return false;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int l = 1,r = *max_element(p.begin(),p.end()) - *min_element(p.begin(),p.end());
        int ans = 0;
        while(l <=r){
            int mid = (l + r)/2;
            if(ispossible(mid,p,m)){
                ans = max(ans,mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
    return ans;
    }
};