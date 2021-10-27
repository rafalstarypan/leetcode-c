// Problem link: https://leetcode.com/problems/decode-ways/

class Solution {
public:   
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 1;
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = s[0]=='0'?0:1;
        
        for (int i = 2; i <= n; i++) {
            int prev = s[i-2] - '0';
            int cur = s[i-1] - '0';

            if (cur > 0) {
                dp[i] = dp[i-1];
            }
            cur += 10*prev;
            if (cur >= 10 && cur <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};