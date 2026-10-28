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
int widthOfBinaryTree(TreeNode* root) {
if (!root) return 0;

    long long ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int n = q.size();
        unsigned long long first = q.front().second;
        unsigned long long last = 0;

        for (int i = 0; i < n; i++) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            unsigned long long idx = curr.second - first;

            last = idx;

            if (node->left)
                q.push({node->left, 2 * idx + 1});

            if (node->right)
                q.push({node->right, 2 * idx + 2});
        }

        ans = max(ans, (long long)(last + 1));
    }

    return ans;
}

};
