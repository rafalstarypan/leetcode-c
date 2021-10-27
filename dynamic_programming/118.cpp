// Problem link: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> row = {1};
        
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(row);
            
            vector<int> new_row = {1};
            for (int j = 0; j < row.size()-1; j++) {
                new_row.push_back(row[j] + row[j+1]);
            }
            new_row.push_back(1);
            
            row = new_row;
        }
        
        return ans;
    }
};