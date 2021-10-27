// Problem link: https://leetcode.com/problems/generate-parentheses/

class Solution {
private:
    bool isValid(int len, int mask) {
        int balance = 0;
        
        for (int bit = 0; bit < len; bit++) {
            if (mask & (1 << bit)) balance++;
            else balance--;
            if (balance < 0) return false;
        }
        
        return balance == 0;
    }
    
    string convertToString(int len, int mask) {
        string res = "";
        
        for (int bit = 0; bit < len; bit++) {
            if (mask & (1 << bit)) res += '(';
            else res += ')';
        }
        
        return res;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int len = n * 2;
        
        for (int mask = 0; mask < (1 << len); mask++) {
            if (__builtin_popcount(mask) != n) continue;
            if (isValid(len, mask)) {
                res.push_back(convertToString(len, mask));
            }
        }
        
        return res;
    }
};