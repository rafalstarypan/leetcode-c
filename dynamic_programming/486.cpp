// Problem link: https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        if (nums.empty()) {
            return true;
        } 
        
        int n = nums.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n, 0);
        }
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] >= 0;
        
    }
};