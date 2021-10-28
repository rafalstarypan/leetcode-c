// Problem link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    
    int m;
    vector<vector<int>> G;
    vector<bool> vis;
    
    void dfs(int v) {
        vis[v] = true;
        for (auto to: G[v]) {
            if (!vis[to]) {
                dfs(to);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges) {
        G.resize(n);
        vis.resize(n, false);
        m = edges.size();
        if (m < n-1) {
            return -1;
        }
        
        for (auto vec: edges) {
            G[vec[0]].push_back(vec[1]);
            G[vec[1]].push_back(vec[0]);
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                answer++;
            }
        }
        
        return answer - 1;
    }
};