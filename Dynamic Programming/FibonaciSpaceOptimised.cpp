class Solution {
    public:
        int fib(int n) {
            if(n<=1) return n;
            int dp[3];
            dp[0]=0;
            dp[1]=1;
            for(int i=1;i<=n-1;i++){
                dp[2]=dp[1]+dp[0];
                dp[0]=dp[1];
                dp[1]=dp[2];
            }
            return dp[2];
        }
    };