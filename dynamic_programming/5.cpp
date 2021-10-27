// Problem link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    
    /*
        dp[i][j] - the substring [i, j] is a palindrome
        Only half of the matrix is filled, as i <= j
        I have to check if s[i] == s[j] and if the shorter, not extended yet substring is a palindrome dp[i+1][j-1]
        
        1   0   1   0   0       s[0] == s[2] && [1,1] is a palindrome
            1   0   1   0       s[1] == s[3] && [2,2] is a palindrome
                1   0   0  
                    1   0
                        1
                        
    */  
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        if (n < 2) {
            return s;
        }
        
        vector<vector<bool>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n, false);
        }
        
        for (int i = 0; i < n; i++) {           // the diagonal represents 1-letter substrings
            dp[i][i] = true;
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j] && ((j-i) < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }     
        
        int len = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] && (j-i+1) > len) {
                    len = j-i+1;
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        
        return ans;
        
    }
};