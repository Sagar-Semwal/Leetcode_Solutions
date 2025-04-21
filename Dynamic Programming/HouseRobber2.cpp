// Approach:
// This is a variation of the House Robber problem where the first and last houses are also adjacent,
// so you cannot rob both the first and the last house.
//
// To handle the circular nature, we split the problem into two linear cases:
// Case 1: Rob houses from index 0 to n-2 (exclude last house)
// Case 2: Rob houses from index 1 to n-1 (exclude first house)
// We compute the result for both cases and return the maximum.
//
// Time Complexity: O(n) — two passes through the array (each O(n)).
// Space Complexity: O(n) — a dp array of size n is used.

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
    
            int dp[n];
            
            // Case 1: Rob houses from index 0 to n-2
            dp[0] = nums[0];
            if (n != 1) dp[1] = max(nums[0], nums[1]);
            for (int i = 2; i < n - 1; i++) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            int max1 = dp[n - 2];
    
            // Case 2: Rob houses from index 1 to n-1
            dp[1] = nums[1];
            if (n != 2) dp[2] = max(nums[1], nums[2]);
            for (int i = 3; i < n; i++) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            int max2 = dp[n - 1];
    
            return max(max1, max2);
        }
    };
    