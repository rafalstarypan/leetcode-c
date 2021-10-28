// Problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    const int inf = 1e9;

    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return make_pair(-inf, -inf);
        }

        int val = root->val;
        pair<int, int> l = make_pair(-inf, -inf);
        pair<int, int> r = make_pair(-inf, -inf);

        if (root->left != NULL) {
            l = dfs(root->left);
        }
        if (root->right != NULL) {
            r = dfs(root->right);
        }

        int firstType = max({val, l.first + val, r.first + val});
        int secondType = max({l.second, r.second, l.first + val + r.first, firstType});

        return make_pair(firstType, secondType);
    }

    int maxPathSum(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
