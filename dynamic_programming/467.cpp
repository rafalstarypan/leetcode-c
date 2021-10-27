// Problem link: https://leetcode.com/problems/unique-substrings-in-wraparound-string/

class Solution {
public:
    
    /* 
        Dla kazdej litery c interesuje mnie tylko najdluzszy poprawny podciag konczacy sie na c
        W przeciwnym razie podciagi beda sie powtarzac
    */  
    
    bool isNext(char a, char b) {
        if (a == 'z' && b == 'a') {
            return true;
        }    
        
        return (b-a) == 1;
    }
    
    int findSubstringInWraproundString(string p) {
        
        int n = p.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> cnt(26, 0);
        
        int i = 0;
        int j = 0;
        int curLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && isNext(p[i-1], p[i])) {
                curLen++;
            } else {
                curLen = 1;
            }
            int pos = p[i] - 'a';
            cnt[pos] = max(cnt[pos], curLen);
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i];
        }
        
        return ans;
    }
};