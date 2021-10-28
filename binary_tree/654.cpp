// Problem link: https://leetcode.com/problems/maximum-binary-tree/

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
    
    TreeNode* go(vector<int> a) {
        int maxi = -1;
        int pos = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > maxi) {
                maxi = a[i];
                pos = i;
            }
        }
        
        if (maxi == -1) return NULL;
        
        TreeNode* node = new TreeNode(maxi);
        vector<int> l, r;
        for (int i = 0; i < pos; i++) {
            l.push_back(a[i]);
        }
        for (int i = pos+1; i < a.size(); i++) {
            r.push_back(a[i]);
        }
        
        node->left = go(l);
        node->right = go(r);
        
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return go(nums);
    }
};