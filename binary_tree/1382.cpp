// Problem link: https://leetcode.com/problems/balance-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int n;
    vector<int> vals;
    
    void dfs(TreeNode* node) {
        n++;
        vals.push_back(node->val);
        if (node->left != NULL) {
            dfs(node->left);
        } 
        if (node->right != NULL) {
            dfs(node->right);
        } 
    }
    
    TreeNode* dfs2(int l, int r) {
        if (l > r) {
            return NULL;
        }
        int m = (l+r) / 2;
        TreeNode* rt = new TreeNode(vals[m]);
        rt->left = dfs2(l, m-1);
        rt->right = dfs2(m+1, r);
        
        return rt;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        n = 0;
        vals.clear();
        dfs(root);
        sort(vals.begin(), vals.end());
        
        TreeNode* rt = dfs2(0, vals.size()-1);
        return rt;
    }
};