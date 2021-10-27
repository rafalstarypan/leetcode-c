// Problem link: https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    int longestStrChain(vector<string>& a) {
        int n = a.size();
        unordered_map<string, int> cnt;
        vector<vector<int>> G(n);
        vector<int> inDeg(n, 0), dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            cnt[a[i]] = i;    
        }
        
        for (int u = 0; u < n; u++) {
            string s = a[u];
            int len = s.size();
            for (int i = 0; i < len; i++) {
                string tmp = "";
                for (int j = 0; j < i; j++) {
                    tmp += s[j];
                }
                for (int j = i+1; j < len; j++) {
                    tmp += s[j];
                }
                if (cnt.count(tmp)) {
                    G[cnt[tmp]].push_back(u);
                    inDeg[u]++;
                }
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        
        int ans = 0;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto to: G[v]) {
                dp[to] = max(dp[to], dp[v] + 1);
                inDeg[to]--;
                if (inDeg[to] == 0) {
                    q.push(to);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};