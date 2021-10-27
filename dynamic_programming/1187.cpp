// Problem link: https://leetcode.com/problems/make-array-strictly-increasing/

class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        int n = a.size();
        if (n == 1) return 0;
        
        sort(b.begin(), b.end());
        
        // minimum value at the end of array after making 'i' swaps
        vector<int> dp(n+1, INT_MAX);
        dp[0] = a[0];
        // swap the first element
        if (b[0] < a[0]) dp[1] = b[0];  
        
        for (int i = 1; i < n; i++) {
            vector<int> new_dp(n+1, INT_MAX);
            // update new_dp[0] - no swaps the initial array is already increasing
            if (a[i] > dp[0]) new_dp[0] = a[i];
            
            for (int j = 1; j <= i+1; j++) {
                // no swap at current position
                if (a[i] > dp[j]) new_dp[j] = a[i];
                
                // swap at current position
                auto nxt = upper_bound(b.begin(), b.end(), dp[j-1]);
                if (nxt != b.end()) {
                    new_dp[j] = min(new_dp[j], *nxt);
                }
            }
            
            dp = new_dp;
        }
        
        for (int i = 0; i <= n; i++) {
            if (dp[i] != INT_MAX) return i;
        }
        
        return -1;
    }
};