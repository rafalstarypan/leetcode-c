// Problem link: https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if (A.size() < 3) {
            return 0;
        }
        
        int n = A.size();
        int i = 2;
        int ans = 0;
        int len = 0;
        
        while (i < n) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                len++;
            } else {
                if (len > 0) {
                    ans += (len * (len+1)) / 2;
                }
                len = 0;
            }
            i++;
        }
        if (len > 0) {
            ans += (len * (len+1)) / 2;
        }
        
        return ans;
    }
};