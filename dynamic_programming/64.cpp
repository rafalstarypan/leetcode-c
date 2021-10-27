// Problem link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m);
        for (int i=0; i<m; i++) {
            dp[i].resize(n, INT_MAX);
        }
        
        dp[0][0] = grid[0][0];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i > 0) dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i][j]);
            }
        }
        
        return dp[m-1][n-1];
    }
};