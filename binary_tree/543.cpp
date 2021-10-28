// Problem link: https://leetcode.com/problems/diameter-of-binary-tree/

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
    
    pair<int, int> dfs(TreeNode* node) {;
        if (node->left == NULL && node->right == NULL) {
            return {0, 0};
        }
                                        
        pair<int, int> fromLeft = {0, 0};
        if (node->left != NULL) {
            fromLeft = dfs(node->left);
            fromLeft.first++;
        }
                                        
        pair<int, int> fromRight = {0, 0};
        if (node->right != NULL) {
            fromRight = dfs(node->right);
            fromRight.first++;
        }
         
        pair<int, int> ret = make_pair(max(fromLeft.first, fromRight.first), max({fromLeft.first +                                      fromRight.first, fromLeft.second, fromRight.second}));
        
        return ret;                                
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        pair<int, int> result = dfs(root);
        
        return max(result.first, result.second);
    }
};