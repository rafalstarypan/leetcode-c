// Problem link: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    
    /*  The sum of a subset must be equal to half of the entire sum
        I just need to check if it is possible to get it
    */
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum%2) {
            return false;
        }
        sum /= 2;
        
        vector<vector<bool>> dp(sum+1);
        for (int i = 0; i <= sum; i++) {
            dp[i].resize(n+1, false);
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = true;
        }
        
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j-1];
                int val = nums[j-1];
                if (i - val >= 0) {
                    dp[i][j] = dp[i][j] | dp[i-val][j-1];
                }
            }
        }
        
        return dp[sum][n];
    }
};