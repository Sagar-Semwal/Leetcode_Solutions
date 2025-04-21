// Approach:
// This solution uses space-optimized Dynamic Programming to calculate the nth Fibonacci number.
// It only keeps track of the last two Fibonacci numbers to compute the next one.
// Base cases: F(0) = 0, F(1) = 1
// For n >= 2, F(n) = F(n-1) + F(n-2)
//
// Time Complexity: O(n) — we iterate from 1 to n-1.
// Space Complexity: O(1) — only a fixed-size array of 3 integers is used.

class Solution {
    public:
        int fib(int n) {
            if (n <= 1) return n;
            int dp[3];
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 1; i <= n - 1; i++) {
                dp[2] = dp[1] + dp[0];
                dp[0] = dp[1];
                dp[1] = dp[2];
            }
            return dp[2];
        }
    };
    