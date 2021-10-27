// Problem link: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        
        int i2 = 2;
        int i3 = 3;
        int i5 = 5;
        int mul2 = 0;
        int mul3 = 0;
        int mul5 = 0;
        
        int ans;
        for (int i=1; i<n; i++) {
            ans = min(i2, i3);
            ans = min(ans, i5);
            dp[i] = ans;
            if (i2 == ans) {
                mul2++;
                i2 = dp[mul2] * 2;
            }
            if (i3 == ans) {
                mul3++;
                i3 = dp[mul3] * 3;
            }
            if (i5 == ans) {
                mul5++;
                i5 = dp[mul5] * 5;
            }
        }
        return dp[n-1];
    }
};