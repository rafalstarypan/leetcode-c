// Problem link: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    
    /*  Najmniejszy element w pozbiorze musi byc dzielnikiem wszystkich pozostalych elementow
        Sortuje elementy wejsciowe
        Nastepnie przechodze od najwiekszych elementow i obliczam rozmiar najwiekszego podzbioru zaczynajacego sie w 'i'
        Po drodze uaktualniam max. rozmiar i z ktorego indeksu sie zaczal oraz from[] - skad przyszla zmiana
        Na koncu odtwarzam wynik z from[]
    */    

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        
        int n = nums.size();
        vector<int> dp(n), from(n);
        
        sort(nums.begin(), nums.end());
        int maxLen = -1;
        int pos = -1;
        
        for (int i = n-1; i >= 0; i--) {
            dp[i] = 1;
            from[i] = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                pos = i;
            }
        }
        
        vector<int> ans;
        while (from[pos] != pos) {
            ans.push_back(nums[pos]);
            pos = from[pos];
        } 
        ans.push_back(nums[pos]);
        
        return ans;
    }
};