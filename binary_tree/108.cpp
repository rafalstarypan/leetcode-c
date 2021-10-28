// Problem link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* createTree(const vector<int>& nums, int L, int R) {
        if (L > R) return nullptr;
        
        int mid = (L + R) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = createTree(nums, L, mid - 1);
        node->right = createTree(nums, mid + 1, R);
        
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return createTree(nums, 0, n - 1);
    }
};