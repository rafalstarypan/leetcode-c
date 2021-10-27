// Problem link: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n);
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (j == i+1 && s[j] == s[i]) {
                    dp[i][j] = 2;
                    continue;
                }
                if (s[j] != s[i]) {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                } else {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
            } 
        }
        
        return dp[0][n-1];
    }
};