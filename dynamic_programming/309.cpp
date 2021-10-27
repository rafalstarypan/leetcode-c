// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    
    /*
    nothing:    0   0   1   2   2
    buy:        -1  -2  -3  1   0
    sell:       0   1   2   -1  3
    */   
    
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty()) {
            return 0;
        }
        
        int n = prices.size();
        int nothing = 0;
        int bought = -prices[0];
        int maxBought = -prices[0];
        int sell = 0;
        int ans = 0;
        
        for (int i = 1; i < n; i++) {
            bought = nothing - prices[i];
            nothing = max({nothing, bought, sell});
            sell = maxBought + prices[i];
            maxBought = max(maxBought, bought);
            ans = max({ans, sell, nothing, bought});
        }
        
        return ans;
        
    }
};