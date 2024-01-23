class ThroneInheritance {
public:
unordered_map<string,vector<string>> pariwar;
unordered_set<string > marehue;
 string nameOfKing;
    ThroneInheritance(string kingName) {
        nameOfKing = kingName;
    }
    
    void birth(string parentName, string childName) {
        pariwar[parentName].push_back(childName);
    }
    
    void death(string name) {
       marehue.insert(name);
    }
    void helper(string par, vector<string> &ans){
        if(marehue.count(par)==0) ans.push_back(par);
        for(auto child:pariwar[par]) helper(child, ans);
    }
    
    vector<string> getInheritanceOrder() {
         vector<string> ans;
        helper(nameOfKing, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */