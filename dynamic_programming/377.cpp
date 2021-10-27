// Problem link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    
    /*
        dp[i][j] - the number of ways to get 'i' using 'j' numbers
    */
    
    long double combinationSum4(vector<int>& nums, int target) {
        
        if (target == 0) {
            return 1;
        } 
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size();
        vector<long  double> dp(target+1, 0);
        
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                int val = nums[j];
                if (i - val >= 0) {
                    dp[i] += dp[i-val];
                }
            }
        }      
        
        return dp[target];
    }
};