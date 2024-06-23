// // class Solution {
// // public:
// //     int longestSubarray(vector<int>& nums, int limit) {
// //         // 8 8
// //         // 8 2
// //         int maxi = nums[0];
// //         int mini = nums[0];
// //         int ans = 0, i = 0,j = 0;
// //         int n = nums.size();
// //         while(i < n && j < n){
// //             maxi = *max_element(nums.begin() + j ,nums.begin() + i);
// //                mini = *min_element(nums.begin() + j , nums.begin() + i);

// //             if(abs(maxi - mini) <= limit) {
// //                 cout<<maxi<<"  - "<<mini<<endl;
// //                 cout<<"index - "<<i<<" "<<j<<endl;
// //                 ans = max(ans,i-j+1);

// //             }
// //             else{
// //                 j++;
// //                maxi = *max_element(nums.begin() + j ,nums.begin() + i);
// //                mini = *min_element(nums.begin() + j , nums.begin() + i);

// //             }
// //             i++;
// //         }
// //         return ans;
// //     }
// // };



// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         deque<int> maxDeque, minDeque;
//         int i = 0, j = 0, n = nums.size(), ans = 0;
        
//         while (i < n) {
//             // Maintain the deques for the current window
//             while (!maxDeque.empty() && nums[i] > maxDeque.back()) {
//                 maxDeque.pop_back();
//             }
//             while (!minDeque.empty() && nums[i] < minDeque.back()) {
//                 minDeque.pop_back();
//             }
//             maxDeque.push_back(nums[i]);
//             minDeque.push_back(nums[i]);
            
//             // Check if the current window is valid
//             if (maxDeque.front() - minDeque.front() <= limit) {
//                 ans = max(ans, i - j + 1);
//             } else {
//                 // If not valid, move the start of the window
//                 if (maxDeque.front() == nums[j]) maxDeque.pop_front();
//                 if (minDeque.front() == nums[j]) minDeque.pop_front();
//                 j++;
//             }
            
//             i++;
//         }
        
//         return ans;
//     }
// };



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = 0, i = 0, j = 0;

        while (i < n) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);

            if (maxi - mini <= limit) {
                ans = max(ans, i - j + 1);
            } else {
                if (nums[j] == maxi) {
                    maxi = *max_element(nums.begin() + j + 1, nums.begin() + i + 1);
                }
                if (nums[j] == mini) {
                    mini = *min_element(nums.begin() + j + 1, nums.begin() + i + 1);
                }
                j++;
            }
            i++;
        }

        return ans;
    }
};
