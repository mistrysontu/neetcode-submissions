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
    int helper(TreeNode *root, bool &res){
        if(root == nullptr) return 0;
        int left = helper(root->left, res) + 1;
        int right = helper(root->right, res) + 1;
        if (abs(left - right) > 1) res = false;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        if(root == nullptr) return true;
        helper(root, res);
        return res;
    }
};
