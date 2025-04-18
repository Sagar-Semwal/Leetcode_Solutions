/*
Approach:
- Use Dynamic Programming to count unique paths from (0,0) to (m-1,n-1).
- Create a 2D dp table where dp[i][j] stores number of ways to reach cell (i,j).
- Base Case: First row and first column have only one way to reach (all rights or all downs).
- Transition: dp[i][j] = dp[i-1][j] + dp[i][j-1]

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
    public:
        int uniquePaths(int m, int n) {
            int dp[m][n];
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
    };
    