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
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    string solve(TreeNode* root) {
        if (!root) return "#";

        string s = to_string(root->val) + "," +
                   solve(root->left) + "," +
                   solve(root->right);

        if (mp[s] == 1)
            ans.push_back(root);

        mp[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};