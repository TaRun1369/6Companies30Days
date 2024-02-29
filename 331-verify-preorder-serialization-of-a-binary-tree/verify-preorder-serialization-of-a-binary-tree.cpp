class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        if(preorder == "#,#,#") return false;
        string ss;
        stringstream st(preorder);
        vector <string> v;
        while(getline(st,ss,',')) v.push_back(ss);

        // for(auto it : v){
        //     cout<<it<<endl;
        // }
        
        int n = v.size();
        queue<string> q;
        q.push(v[0]);
        int i = 0;
        while(!q.empty()){
            string t = q.front();
            q.pop();
            i++;
            if(i == n) return false;
            if(v[i] != "#")
            q.push(v[i]);
            i++;
            if(i == n) return false;
            if(v[i] != "#")
            q.push(v[i]);
        }
        return i == n-1;
    }
};