// Problem link: https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        vector<int> dp(n+1);
        dp[1] = 10;
        
        for (int i = 2; i <= n; i++) {
            int tmp = 9;
            int mul = 9;
            for (int j = 1; j < i; j++) {
                tmp *= mul;
                mul--;
            }
            dp[i] = dp[i-1] + tmp;
        }
        return dp[n];
    }
};