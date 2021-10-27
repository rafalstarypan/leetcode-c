// Problem link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(2);
        dp[0].resize(n+1, 0);
        dp[1].resize(n+1, 0);
        dp[0][1] = A[0];
        dp[1][1] = 0;
        
        for (int i=2; i<=n; i++) {
            int j = i-1;
            dp[0][i] = max(dp[0][i-2], dp[1][i-2]);
            dp[0][i] += A[j];
            dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
        }
        

        return max(dp[0][n], dp[1][n]);
        
    }
};