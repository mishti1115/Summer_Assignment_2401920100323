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
    int ans = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info solve(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Info l = solve(root->left);
        Info r = solve(root->right);

        if (l.isBST && r.isBST &&
            l.maxVal < root->val && root->val < r.minVal) {

            int sum = l.sum + r.sum + root->val;

            ans = max(ans, sum);

            return {
                true,
                sum,
                min(root->val, l.minVal),
                max(root->val, r.maxVal)
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};