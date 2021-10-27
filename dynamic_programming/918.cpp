// Problem link: https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        
        int n = a.size();
        int local = a[0];
        int ans = local;
        
        for (int i = 1; i < n; i++) {
            local = max(local + a[i], a[i]);
            ans = max(ans, local);
        }
        
        multiset<int> suff;
        suff.insert(0);
        vector<int> curSuff(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            curSuff[i] = curSuff[i+1] + a[i];
            suff.insert(curSuff[i]);
        }
        
        int pref = 0;
        for (int i = 0; i < n; i++) {
            pref += a[i];
            suff.erase(suff.find(curSuff[i]));
            ans = max(ans, pref + *suff.rbegin());
        }
        
        return ans;
    }
};