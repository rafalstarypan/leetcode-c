// Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
public:
    
    int ans, pos, which;
    
    void dfs(TreeNode* node) {
        
        if (node->left) {
            dfs(node->left);
        }
        
        pos++;
        if (pos == which) {
            ans = node->val;
        }
        
        if (node->right) {
            dfs(node->right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        pos = 0;
        which = k;
        
        dfs(root);
        
        return ans;
    }
};