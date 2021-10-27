// Problem link: https://leetcode.com/problems/stone-game/

class Solution {
private:
    vector<vector<int>> dp;
    vector<int> pref;
    
    int getSubarraySum(int L, int R) {
        if (L > R) return 0;
        int res = pref[R];
        if (L > 0) res -= pref[L-1];
        return res;
    }
    
    int calcDp(int L, int R, const vector<int>& piles) {
        if (L == R) return piles[L];
        if (dp[L][R] != -1) return dp[L][R];
        
        // choose leftmost pile
        int leftScore = piles[L] + getSubarraySum(L + 1, R) - calcDp(L + 1, R, piles);
        
        // choose rightmost pile
        int rightScore = piles[R] + getSubarraySum(L, R - 1) - calcDp(L, R - 1, piles);
        
        return dp[L][R] = max(leftScore, rightScore);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        dp.resize(n, vector<int>(n, -1));
        pref.resize(n);
        
        pref[0] = piles[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + piles[i];
        }
        
        int alexScore = calcDp(0, n-1, piles);
        return 2 * alexScore > sum;
    }
};