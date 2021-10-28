// Problem link: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    
    vector<vector<int>> G;
    vector<int> color;
    bool ans;
    
    void dfs(int v, int c) {
        color[v] = c;
        int newColor = c ^ 1;
        for (auto to: G[v]) {
            if (color[to] != -1 && color[to] != newColor) ans = false;
            if (color[to] == -1) {
                dfs(to, newColor);
            }
        }
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        G.resize(N+1);
        color.resize(N+1, -1);
        ans = true;
        
        for (auto vec: dislikes) {
            int u = vec[0];
            int v = vec[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        for (int i = 1; i <= N; i++) {
            if (color[i] == -1) {
                dfs(i, 0);
            }
        }
        
        return ans;
    }
};