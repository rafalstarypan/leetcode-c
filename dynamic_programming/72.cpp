// Problem link: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string s, string t) {
        
        s = '#' + s;
        t = '#' + t;
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++){
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};