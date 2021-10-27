// Problem link: https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    
    /*
        G(n) -> the nth Catalan number
        F(i, n) -> the number of unique BST's with 'i' as the root ans 'n' nodes
        
        G(n) = F(i, n) + F(i+1, n) + ... + F(n, n)
        F(i, n) = G(i-1) * G(n-i)
        
    */
    
    int numTrees(int n) {
        
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int tmp = dp[j-1] * dp[i - j];
                dp[i] += tmp;
            }
        }
        
        return dp[n];
    }
};