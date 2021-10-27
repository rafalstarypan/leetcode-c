// Problem link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        int n = a.size();
        int best = a[0];
        int cur = a[0];
        
        for (int i = 1; i < n; i++) {
            cur = max(a[i], cur + a[i]);
            best = max(best, cur);
        }
        
        return best;
    }
};