//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    string ans = "";
    int count = 0;
    for(int i = 1;i<src.size();i++){
        if(src[i] == src[i-1]){
            count++;
        }
        else{
            ans += src[i-1];
            ans += to_string(count + 1);
            count = 0;
        }
        
    }
    count++;
    if(count != 0){
        ans += src[src.size()-1];
        ans += to_string(count);
    }
    
    return ans;
  //Your code here 
}     
 
