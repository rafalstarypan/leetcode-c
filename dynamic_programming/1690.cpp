// Problem link: https://leetcode.com/problems/stone-game-vii/

class Solution {
public:
    
    int n;
    vector<int> pref;
    vector<vector<int>> dp;
    
    int getSum(int L, int R) {
        if (L > R) return 0;
        int res = pref[R];
        if (L > 0) res -= pref[L-1];
        return res;
    }
    
    int rec(int L, int R, bool who) {
        if (L > R) return 0;
        if (dp[L][R] != -1) return dp[L][R];
        
        int moveLeft = rec(L+1, R, !who);
        int moveRight = rec(L, R-1, !who);
        
        if (who) {
            moveLeft += getSum(L+1, R);
            moveRight += getSum(L, R-1);
        } else {
            moveLeft -= getSum(L+1, R);
            moveRight -= getSum(L, R-1);
        }
        
        if (who) {
            dp[L][R] = max(moveLeft, moveRight);
        } else {
            dp[L][R] = min(moveLeft, moveRight);
        }
        
        return dp[L][R];
    }
    
    int stoneGameVII(vector<int>& a) {
        n = a.size();
        pref.resize(n);
        dp.resize(n, vector<int>(n, -1));
        
        pref[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + a[i];
        }
        
        return rec(0, n-1, true);
    }
};