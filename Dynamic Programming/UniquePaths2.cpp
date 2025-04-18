/*
Approach:
- Bottom-up Dynamic Programming to count unique paths avoiding obstacles.
- If a cell contains an obstacle (1), set its dp value to 0.
- Start from bottom-right and move to top-left, adding ways from right and down cells.
- Base case: dp[n-1][m-1] = 1 if it's not an obstacle.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

class Solution {
    public:
        int n, m;
        vector<vector<long long int>> dp;
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            n = obstacleGrid.size();
            m = obstacleGrid[0].size();
    
            dp.clear();
            dp.resize(105, vector<long long int>(105, 0));
    
            if (obstacleGrid[n-1][m-1] == 1) return 0; //final cell me hi obstacle h
            dp[n-1][m-1] = 1; //last cell se last cell pe jane ka trika is 1
    
            for (int i = n - 2; i >= 0; i--) {
                if (obstacleGrid[i][m-1] == 1) dp[i][m-1] = 0; //if there is obstacle then in dp mark it as 0.
                else dp[i][m-1] = dp[i+1][m-1];  //vrna jo niche ans h voi ans hoga 
            }
    
            for (int i = m - 2; i >= 0; i--) {
                if (obstacleGrid[n-1][i] == 1) dp[n-1][i] = 0;
                else dp[n-1][i] = dp[n-1][i+1];
            }
    
            for (int i = n - 2; i >= 0; i--) {
                for (int j = m - 2; j >= 0; j--) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
    
            return dp[0][0];
        }
    };
    