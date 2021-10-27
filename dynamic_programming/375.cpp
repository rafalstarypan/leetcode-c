// Problem link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:  
    int getMoneyAmount(int n) {
        
        const int inf = 1e9;
        
        if (n == 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n+1);        // dp[i][j] - money needed to be sure to complete interval [i, j]
        for (int i = 0; i <= n; i++) {
            dp[i].resize(n+1, 0);
        }
        
        for (int len = 2; len <= n; len++) {        // iterate over lengths of intervals, first compute shorter
            for (int i = 1; i + len - 1 <= n; i++) {    // 'i' - the start of the interval
                
                dp[i][i + len - 1] = inf;
                for (int g = i; g <= i + len - 1; g++) {     // 'g' - the number I am guessing
                                                            // After the guess I take cost 'g' and problem
                                                            // divides into left and right intervals - I take maximum of those
                    int maxCostGuess;
                    if (g == n) {
                        maxCostGuess = dp[i][g-1] + g;  // no right interval possible
                    } else {
                        maxCostGuess = max(dp[i][g-1], dp[g+1][i + len - 1]) + g;
                    }
                    dp[i][i + len - 1] = min(dp[i][i + len - 1], maxCostGuess);     // I choose the optimal guess 'g'
                }
            }
        }
        
        return dp[1][n];
        
    }
};