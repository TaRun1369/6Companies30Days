class Solution {
public:
bool check(string a,string b){
    int count = 0;
    for(int i= 0;i<a.size();i++){
        if(a[i] != b[i]) count++;
    }
    return count == 1;
}

int  bfs(set<string> s,string st,string ed){
    queue<pair<string,int>> q;
    // set<string> visited;
    q.push({st,1});
    // int ans = INT_MAX;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t.first == ed) return t.second;
        string word = t.first;
        for (int i = 0; i < t.first.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, t.second + 1});
                    }
                }
                word[i] = original;
            }      
    }

    return 0;
}
    int ladderLength(string st, string en, vector<string>& wl) {
        // wl.push_back(hit);
        int n = wl.size();
        // vector<vector<string>> adj(n);
        // for(int i= 0;i<n;i++){
        //     for(int j= i+1;i<n;i++){
        //             if(check(it,is)){
        //                 adj[i].push_back(wl[j]);
        //                 adj[j].push_back(wl[i]);
        //             }
        //     }
        // }

        // set banao

        set<string> s(wl.begin(),wl.end());
        s.insert(st);

        return bfs(s,st,en);
    }
};