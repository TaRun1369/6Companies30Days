class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>w;
        for(int i=0;i<startWords.size();i++)
        {
            sort(startWords[i].begin(),startWords[i].end());
            //cout<<startWords[i]<<" ";
            w.insert(startWords[i]);
        }
        int c=0;string tmp="",x="";
        for(int i=0;i<targetWords.size();i++)
        {
            tmp=targetWords[i];
            sort(tmp.begin(),tmp.end());           
            for(int j=0;j<tmp.length();j++)
            {
                x=tmp.substr(0,j)+tmp.substr(j+1);//generating our substring
                if(w.find(x)!=w.end())//substring found
                {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};