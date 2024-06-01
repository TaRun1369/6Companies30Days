class Solution {
public:
    // Recursive function to calculate the sum of XORs of all subsets
    void solve(vector<int> &nums, int index, int &xorrsum, int xorr) {
        if (index >= nums.size()) {
            // Base case: if we have considered all elements, add current XOR to sum
            xorrsum += xorr;
            return;
        }
        
        // Recursive case: include nums[index] in the subset
        solve(nums, index + 1, xorrsum, xorr ^ nums[index]);
        // Recursive case: exclude nums[index] from the subset
        solve(nums, index + 1, xorrsum, xorr);
    }

    // Function to initiate the recursive process and return the result
    int subsetXORSum(vector<int>& nums) {
        int xorrsum = 0;
        solve(nums, 0, xorrsum, 0);  // Start the recursive process
        return xorrsum;
    }
};