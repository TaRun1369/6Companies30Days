// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, long long k) {
//         // currsum - 1  2  3 2 
//         // len  -    1  2  3 2
//         // preod -   1  4  9 4
//         // ans -        1 ,3  5
//         int n = nums.size();
//         int i = 0,j = n-1;
//         int currsum = 0,len = 0;
//         int ans = 0;
//         while(i < n && j < n){
//             currsum += nums[i];
//             len++;
//             long long prod = currsum*len*1ll;

            
//             if(prod > k){
//                 while(j <= i && prod > k){
//                     currsum -= nums[j];
//                     len--;
//                     prod = currsum*len*1ll;
//                     j++;    
//                 }
//             }
//             if(prod < k){
//                 ans += (i - j + 1);
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long currsum = 0;
        int len = 0;
        long long ans = 0;

        while (i < n) {
            currsum += nums[i];
            len++;
            long long prod = currsum * len;

            while (j <= i && prod >= k) {
                currsum -= nums[j];
                len--;
                prod = currsum * len;
                j++;
            }

            ans += (i - j + 1);
            i++;
        }

        return ans;
    }
};
