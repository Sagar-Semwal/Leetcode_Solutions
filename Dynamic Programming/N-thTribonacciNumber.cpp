// Approach:
// This solution uses Dynamic Programming (DP) to calculate the nth Tribonacci number.
// The Tribonacci sequence is defined as:
// T(0) = 0, T(1) = 1, T(2) = 1, and for n >= 3,
// T(n) = T(n-1) + T(n-2) + T(n-3)
//
// Time Complexity: O(n) — we compute each value from 3 to n once.
// Space Complexity: O(n) — we use a dp array of size n+1 to store results.

class Solution {
    public:
        int tribonacci(int n) {
            if (n <= 1) return n;
            if (n == 2) return 1;
    
            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
    
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
    
            return dp[n];
        }
    };
    