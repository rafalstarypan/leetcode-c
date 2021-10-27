// Problem link: https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:
    
    bool isSplitable(vector<int> v) {
        int n = v.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            long long taken = 0;
            long long notTaken = 0;
            
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) {
                    taken += v[bit];
                } else {
                    notTaken += v[bit];
                }
            }
            
            if (taken == notTaken && taken > 0) return true;
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        
        int totalLength = 0;
        for (int match: matchsticks) {
            totalLength += match;
        }
        
        if (totalLength == 0 || totalLength % 4) return false;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            long long horizontal = 0;
            long long vertical = 0;
            
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) {
                    horizontal += matchsticks[bit];
                } else {
                    vertical += matchsticks[bit];
                }
            }
            
            if (horizontal != vertical || horizontal % 2 || vertical % 2) continue;
            
            vector<int> horizontalMatches, verticalMatches;
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) {
                    horizontalMatches.push_back(matchsticks[bit]);
                } else {
                    verticalMatches.push_back(matchsticks[bit]);
                }
            }
            
            if (isSplitable(horizontalMatches) && isSplitable(verticalMatches)) return true;
        }
        
        return false;
    }
};