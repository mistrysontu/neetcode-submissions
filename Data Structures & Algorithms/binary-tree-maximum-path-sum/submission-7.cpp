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
    int helper(TreeNode *root, int &res){
        if(!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        if(res < 0 && left == 0 && right == 0){
            res = max(res, root->val);
        }
        int nodeSum = root->val + (left > 0 ? left: 0) + (right > 0 ? right: 0);
        res = max(res, nodeSum);
        root->val = max(0, root->val + max((left > 0? left: 0),  (right > 0 ? right: 0)));
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1001;
        helper(root, res);
        return res;
    }
};
