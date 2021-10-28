// Problem link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    int pos;
    vector<int> a;

    TreeNode* rec(int l, int r) {
        if (pos >= n) return NULL;
        int x = a[pos];
        if (x < l || x > r) return NULL;


        TreeNode* root = new TreeNode(x);
        pos++;

        root->left = rec(l, x-1);
        root->right = rec(x+1, r);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        a = preorder;
        n = a.size();
        pos = 0;

        return rec(INT_MIN, INT_MAX);
    }
};
