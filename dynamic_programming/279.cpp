// Problem link: https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int i = 1;
        while (i*i <= n) {
            squares.push_back(i*i);
            i++;
        }
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < squares.size(); j++) {
                int tmp = squares[j];
                if (i - tmp >= 0) {
                    dp[i] = min(dp[i], dp[i-tmp] + 1);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};