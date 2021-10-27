// Problem link: https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        s = '#' + s;
        t = '#' + t;
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(m, 0);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (s[i] == t[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};