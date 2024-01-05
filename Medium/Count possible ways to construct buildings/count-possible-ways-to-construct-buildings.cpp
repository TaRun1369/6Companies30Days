//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    int mod = int(1e9 + 7);
	    int prev1 = 1;
	    int prev2 = 1;
	   // long long curr;
	    if(N == 1) return 4;
	    for(int i = 0;i<N;i++){
	       // int temp = curr;
	        long long curr = (prev1+prev2)%mod;
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    
	    return (int)((prev1*1LL*prev1*1LL)%mod);
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends