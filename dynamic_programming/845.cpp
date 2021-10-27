// Problem link: https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& a) {
        if (a.empty()) {
            return 0;
        }
        
        int n = a.size();
        vector<int> pref(n), suff(n);
        
        pref[0] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = 1;
            if (a[i] > a[i-1]) {
                pref[i] = pref[i-1] + 1;
            }
        }
        
        suff[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            suff[i] = 1;
            if (a[i] > a[i+1]) {
                suff[i] = suff[i+1] + 1;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            if (pref[i] == 1 || suff[i] == 1) continue;
            ans = max(ans, pref[i] + suff[i] - 1);
        }
        
        return ans;
    }
};