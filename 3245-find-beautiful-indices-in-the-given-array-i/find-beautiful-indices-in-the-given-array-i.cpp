class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> mindex,sindex,ans;
        int pos = s.find(a, 0) ;
        while(pos != string::npos)
        {
            mindex.push_back(pos);
            pos = s.find(a,pos+1);
        }


        int pos1 = s.find(b,0) ;
        while(pos1 != string::npos)
        {
            sindex.push_back(pos1);
            pos1 = s.find(b,pos1+1);
        }

        // sort(mindex.begin(),mindex.end(),greater<int>());

        // sort(mindex.begin(),sindex.end());

        int i = 0,j = 0;
        // mindex - 33 16
        // sindex - 4 18 
        for(auto it : mindex){
            for(auto iy : sindex){
                if(abs(it-iy) <= k){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};