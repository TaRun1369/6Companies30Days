// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
       
//         int ans = 0;
//         int n = nums.size();
//         for(int i = 0;i<n-k + 1;i++){
//             if(nums[i] == 0){
//                 for(int j = i;j<i+k;j++){
//                     nums[j] = !nums[j];
//                 }
//                 ans++;
//             }
//         }
//         int flag = 0;
//         int i = n-1;
//         while(i >= n-k){
//             if(nums[i] == 0){
//                 // cout<<i<<endl;
//                 flag = 1;
//                 break;
//             }
//             i--;
//         }

//         if(flag == 1) return -1;
//         else return ans;
//     }
// };
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n, 0);
        int flip_count = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flip_count ^= flip[i - k];
            }
            
            if ((nums[i] ^ flip_count) == 0) {
                if (i + k > n) return -1;
                flip[i] = 1;
                flip_count ^= 1;
                ++ans;
            }
        }
        
        return ans;
    }
};
