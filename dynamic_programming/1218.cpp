// Problem link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // length of the longest subsequence ending at number i
        unordered_map<int, int> dp;
        
        for (int x: arr) {
            int myBest = 1;
            // check the previous element in the arithmetic sequence
            int prv = x - difference;
            if (dp.count(prv)) {
                myBest = dp[prv] + 1;
            }
            dp[x] = max(dp[x], myBest);
        }
        
        int ans = 0;
        for (auto it: dp) {
            ans = max(ans, it.second);
        }
        
        return ans;
    }
};