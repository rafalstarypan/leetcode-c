// Problem link: https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    
    const int MOD = 1e9+7;
    
    int kInversePairs(int n, int k) {
        
        // dp[j] - number of arrays with 'j' inversions
        vector<int> dp(k+1, 0);
        dp[0] = 1;  // array of length 1 - [1] has no inversions
        
        for (int i = 2; i <= n; i++) {
            
            // calculate prefix sums
            for (int j = 1; j <= k; j++) {
                dp[j] += dp[j-1];
                dp[j] %= MOD;
            }
            
            vector<int> new_dp(k+1, 0);
            for (int j = 0; j <= k; j++) {
                
                // dp[i][j] = dp[i-1][j-i+1] + ... + dp[i-1][j]
                int l = max(0, j - i + 1);
                int r = j;
                
                int tmp = dp[r];
                if (l > 0) tmp -= dp[l-1];
                if (tmp < 0) tmp += MOD;
                
                new_dp[j] = tmp;
            }
            
            dp = new_dp;
        }
        
        return dp[k];
    }
};