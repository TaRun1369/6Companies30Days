//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        priority_queue<pair<int,int>>pq;
        
        for(int i = n-1;i>= 0 ;i--){
            if(pq.empty() || pq.top().first < arr[i]){
                pq.push({arr[i],i});
            }
        }
        int maxi = 0,ans = 0;
        for(int i  = 0;i<n;i++){
            if(arr[i] <= pq.top().first){
                while(!pq.empty() && pq.top().first >= arr[i]){
                    ans = pq.top().second - i;
                    maxi = max(maxi ,ans);
                    pq.pop();
                }
            }
            
        }
        return maxi;
        // Your code here
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends