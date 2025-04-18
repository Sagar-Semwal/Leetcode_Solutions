// 🔍 Problem: Leetcode 45 - Jump Game II
// 🧠 Approach: Top-down Dynamic Programming (Recursion + Memoization)
// -----------------------------------------------------------
// For each index, we try all possible jumps (1 to nums[i]) and recursively
// find the minimum number of jumps needed to reach the end from each position.
// We memoize the result to avoid recomputation.
//
// ⚠️ Optimization: Before doing `1 + temp`, we check if `temp != INT_MAX`
// to prevent integer overflow (undefined behavior).
//
// ⏱️ Time Complexity: O(n^2) in the worst case (if nums[i] = n-i-1 for all i)
// 📦 Space Complexity: O(n) for the dp array + O(n) recursion stack
// -----------------------------------------------------------

class Solution {
    public:
        int dp[10005]; 
    
        // Recursive helper function 
        int solve(int i, vector<int>& nums) {
            int n = nums.size();
    
            // Base case: If we've reached or crossed the last index, no more jumps are needed
            if (i >= n - 1) return 0;
    
            // Return already computed result
            if (dp[i] != -1) return dp[i];
    
            int ans = INT_MAX;
    
            // Try all jump lengths from 1 to nums[i]
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    int temp = solve(i + j, nums);  
    
                    // Important check:
                    // If the recursive call returns INT_MAX, it means that path is not valid/reachable.
                    // Doing 1 + INT_MAX would cause integer overflow (undefined behavior).
                    if (temp != INT_MAX) {
                        ans = min(ans, 1 + temp); 
                    }
                }
            }
    
            return dp[i] = ans; 
        }
    
        int jump(vector<int>& nums) {
            memset(dp, -1, sizeof(dp));  
            return solve(0, nums);  
        }
    };
    