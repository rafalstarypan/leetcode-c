// Problem link: https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        int n = stations.size();
        vector<long long> dp(n, 0);
        dp[0] = startFuel;
        int prvStation = 0;
        
        for (int i = 0; i < n; i++) {
            vector<long long> new_dp(n+1, -1);
            for (int j = 0; j <= i; j++) {
                int dist = stations[i][0] - prvStation;
                
                // no refueling at previous station
                if (dp[j] >= dist) new_dp[j] = dp[j] - dist;
                
                // refuel at previous station
                if (j > 0) {
                    if (dp[j-1] != -1 && dp[j-1] + stations[i-1][1] >= dist) {
                        new_dp[j] = max(new_dp[j], dp[j-1] + stations[i-1][1] - dist);
                    }
                }
            }
            
            dp = new_dp;
            prvStation = stations[i][0];
        }
        
        for (int i = 0; i < n; i++) {
            if (dp[i] > -1) return i;
        }
        
        return -1;
    }
};