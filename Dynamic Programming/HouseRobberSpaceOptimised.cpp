// Approach:
// This solution uses space-optimized Dynamic Programming to solve the House Robber problem.
// The goal is to find the maximum amount of money you can rob without robbing two adjacent houses.
// At each house, you decide whether to rob it (and add its value to dp[i-2]) or skip it (take dp[i-1]).
//
// Transition:
// dp[i] = max(arr[i] + dp[i-2], dp[i-1])
//
// Time Complexity: O(n) — we iterate through the array once.
// Space Complexity: O(1) — only a fixed-size array of 3 integers is used.

class Solution {
    public:
        int rob(vector<int>& arr) {
            int n = arr.size();
            if (n == 1) return arr[0];
            if (n == 2) return max(arr[0], arr[1]);
    
            int dp[3];
            dp[0] = arr[0];
            dp[1] = max(arr[0], arr[1]);
            for (int i = 2; i < n; i++) {
                dp[2] = max(arr[i] + dp[0], dp[1]);
                dp[0] = dp[1];
                dp[1] = dp[2];
            }
            return dp[2];
        }
    };
    