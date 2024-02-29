class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        map<int,int> mp;
        for(auto it : fronts){
            mp[it]++;
        }
        for(auto it : backs){
            mp[it]++;
        }
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        set<int> nalayak;
        for(int i = 0;i<fronts.size();i++){
            if(fronts[i] == backs[i]) nalayak.insert(fronts[i]);
        }

        for(auto it : mp){

            if(nalayak.find(it.first) == nalayak.end() && it.second <= fronts.size()) return it.first;
        }

        return 0;
    }
};