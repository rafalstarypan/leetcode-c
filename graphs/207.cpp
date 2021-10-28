// Problem link: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        vector<int> inDeg(n, 0);
        vector<vector<int>> G(n);
        for (auto e: edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            inDeg[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cnt++;
            for (int to: G[v]) {
                inDeg[to]--;
                if (inDeg[to] == 0) {
                    q.push(to);
                }
            }
        }
        
        return cnt == n;
    }
};