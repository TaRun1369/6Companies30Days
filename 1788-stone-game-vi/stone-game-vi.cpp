class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        vector<pair<int,int>> sum;
        int n = av.size();
        for(int i = 0;i<n;i++){
            sum.push_back({av[i] + bv[i],i});

        }

        sort(sum.rbegin(),sum.rend());
        int asum = 0,bsum = 0;
        for(int i = 0;i<n;i++){
            if(i %2 == 0){
                // cout<<sum[i]<<endl;
                asum += (sum[i].first - bv[sum[i].second]);
            }
            else{
                bsum += (sum[i].first - av[sum[i].second]);
            }
        }
        cout<<"asum" <<asum<<endl;
        cout<<"bsum" <<bsum<<endl;
        if(asum == bsum){
            return 0;
        }
        else if(asum > bsum) return 1;
        else return -1;
    }
};