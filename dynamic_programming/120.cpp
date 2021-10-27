// Problem link: https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        
        for (int i=1; i<n; i++) {
            vector<int> tmp;
            int s = triangle[i].size();
            tmp.resize(s, INT_MAX);
            for (int j=0; j<s; j++) {
                if (j > 0) tmp[j] = min(dp[j-1] + triangle[i][j], tmp[j]);
                if (j < dp.size()) tmp[j] = min(tmp[j], dp[j] + triangle[i][j]);
            }
            dp = tmp;
        }
        
        return *min_element(dp.begin(), dp.end());
        
    }
};