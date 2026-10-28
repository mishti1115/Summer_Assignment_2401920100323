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
unordered_map<int, int> mp;
int idx = 0;

TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int l, int r) {
    if (idx >= preorder.size() || l > r)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[idx++]);

    if (l == r)
        return root;

    int leftRoot = preorder[idx];
    int mid = mp[leftRoot];

    root->left = solve(preorder, postorder, l, mid);

    root->right = solve(preorder, postorder, mid + 1, r - 1);

    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    idx = 0;
    mp.clear();

    for (int i = 0; i < postorder.size(); i++)
        mp[postorder[i]] = i;

    return solve(preorder, postorder, 0, postorder.size() - 1);
}


};
