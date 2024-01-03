class Solution {
public:

    void fun(int k,int n,set<vector<int>> &s,vector<int> &v,vector<int> &temp,int start){
        if(k ==0 && n == 0){
            cout<<"aaya idhar"<<endl;
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        if(k <= 0 || n <= 0){
            cout<< "idharrrrrr dekeh"<<endl;
            for(auto it : temp){
                cout<<it<<endl;
            }
            return;
        }
        
        for(int i = start;i<=9;i++){
            if(!v[i]){
                cout<<"curr i "<<i<<endl;
                v[i] = 1;
                temp.push_back(i);
                cout<<k<<endl;
                // k--;
                fun(k-1,n-i,s,v,temp,i+1);
                v[i] = 0;
                cout<<"kuch pop hua"<<endl;
                temp.pop_back();
                // k++;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> s;
        vector<int> v (10,0);
        vector<int> temp;
        int start = 1;
        fun(k,n,s,v,temp,start);
        vector<vector<int>> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};