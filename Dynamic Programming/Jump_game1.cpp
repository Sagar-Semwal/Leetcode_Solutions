// 🔍 Problem: Leetcode 55 - Jump Game I
// ✅ Approach: Top-down recursion with memoization (DP)
// ✔️ Optimization: Early exit if we can reach the end directly
// ⏱️ Time: O(n^2) worst case
// 📦 Space: O(n) for dp
// 💡 Idea: Try all jumps from current index, memoize result for future

class Solution {
    public:
        vector<int> dp;
    
        bool helper(int idx, vector<int>& nums) {
            if (idx >= nums.size() - 1) return true;
            if (dp[idx] != -1) return dp[idx];
            if (nums[idx] >= nums.size() - 1 - idx) return true;
    
            bool ans = false;
            for (int i = 1; i <= nums[idx]; i++) {
                ans = ans || helper(idx + i, nums);
                if (ans == true) break;
            }
    
            return dp[idx] = ans;
        }
    
        bool canJump(vector<int>& nums) {
            dp.resize(nums.size(), -1);
            return helper(0, nums);
        }
    };
    