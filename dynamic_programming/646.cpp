// Problem link: https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        if (n == 0) {
            return 0;
        }
        vector<pair<int, int>> v;
        vector<int> dp(n);
        
        for (int i = 0; i < n; i++) {
            v.push_back({pairs[i][1], pairs[i][0]});
        }
        sort(v.begin(), v.end());
        
        dp[n-1] = 1;
        
        for (int i = n-2; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i+1; j < n; j++) {
                if (v[j].second > v[i].first) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
         
        return dp[0];
    }
};