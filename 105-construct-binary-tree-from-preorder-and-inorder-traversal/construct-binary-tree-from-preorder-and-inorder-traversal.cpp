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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> id;
        for(int i=0;i<inorder.size();i++){
            id[inorder[i]] = i;
        }
        int index = 0;
        return fun(preorder,id,index,0,inorder.size()-1);
    }

    TreeNode* fun(vector<int>& preorder, unordered_map<int,int>& id,int& index,int low,int high){
         if(low>high) return NULL;
         int val = preorder[index];
        TreeNode* node = new TreeNode(val);
        
     int idx = id[val];
        index++;
        node->left = fun(preorder,id,index,low,idx-1);
        node->right = fun(preorder,id,index,idx+1,high);
        return node;

    }
};