// Problem link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        
        unordered_map<int, double> sum, cnt;
        queue<pair<TreeNode*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            TreeNode* v = q.front().first;
            int dep = q.front().second;
            q.pop();
            
            sum[dep] += v->val;
            cnt[dep]++;
            
            if (v->left != NULL) {
                q.push(make_pair(v->left, dep+1));
            }
            if (v->right != NULL) {
                q.push(make_pair(v->right, dep+1));
            }
        }
        
        int h = sum.size();
        vector<double> result(h);
        
        for (auto it: sum) {
            int level = it.first;
            double s = it.second;
            s /= cnt[level];
            result[level] = s;
        }
        
        return result;
    }
};