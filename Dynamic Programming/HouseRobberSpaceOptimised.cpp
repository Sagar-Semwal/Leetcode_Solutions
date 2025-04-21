class Solution {
    public:
        int rob(vector<int>& arr) {
            int n=arr.size();
            if(n==1) return arr[0];
            if(n==2) return max(arr[0],arr[1]);
            int dp[3];
            dp[0]=arr[0];
            dp[1]=max(arr[0],arr[1]);
            for(int i=2;i<n;i++){
                dp[2]=max(arr[i]+dp[0],dp[1]);
                dp[0]=dp[1];
                dp[1]=dp[2];
            }
            return dp[2];
        }
    };