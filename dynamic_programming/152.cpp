// Problem link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    
    /*  Maksymalny iloczyn mozna otrzymac z zaczynajac nowy przedzial,
        przedluzajac aktualnie najwiekszy przedzial (nums[i] >= 0) lub przedluzajac 
        aktualnie najmniejszy przedzial (nums[i] < 0)
    */
    
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int localMax, localMin, globalMax;
        
        localMax = localMin = globalMax = nums[0];
        
        for (int i = 1; i < n; i++) {
            int tmp = localMax;
            localMax = max(nums[i], tmp*nums[i]);
            localMax = max(localMax, localMin*nums[i]);
            
            localMin = min(nums[i], localMin*nums[i]);
            localMin = min(localMin, tmp*nums[i]);
            
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};