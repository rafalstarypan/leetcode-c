// Problem link: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<bool> l(N+1, false);
        vector<int> r(N+1, 0);
        
        for (auto v: trust) {
            int x = v[0];
            int y = v[1];
            l[x] = true;
            r[y]++;
        }
        
        for (int i = 1; i <= N; i++) {
            if (!l[i] && r[i] == N-1) {
                return i;
            }
        }
        
        return -1;
    }
};