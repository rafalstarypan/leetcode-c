// Problem link: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                string tmp = wordDict[j];
                int m = tmp.size();
                if (i-m < 0) continue;
                dp[i] = dp[i] | (dp[i-m] && s.substr(i-m, m) == tmp);
            }
        }
        
        return dp[n];
        
    }
};