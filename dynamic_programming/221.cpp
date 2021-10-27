// Problem link: https://leetcode.com/problems/maximal-square/

class Solution {
public:

    /*  dp[i][j] - najdluzszy bok kwadratu konczacy sie w (i, j)
        Jesli matrix[i][j] == '0', to nie ma kwadratu, wiec dp[i][j] = 0
        W przeciwnym wypadku wybieram minimum z przekatnej, gory i dolu, poniewaz kwadrat
        musi byc rozciagniety rownomiernie we wszystkich tych kierunkach i dodaje do tego 1
        przedluzajac kwadrat o aktualne pole
    */


    int maximalSquare(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = matrix[0][i]-'0';
            ans = max(ans, dp[i]);
        }

        for (int i = 1; i < n; i++) {
            vector<int> tmp(m, 0);
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') continue;
                int a, b, c;
                a = dp[j];
                if (j > 0) {
                    b = dp[j-1];
                    c = tmp[j-1];
                } else {
                    b = c = 0;
                }
                tmp[j] = min({a, b, c}) + 1;
                ans = max(ans, tmp[j]);
            }
            dp = tmp;
        }

        return ans * ans;
    }
};
