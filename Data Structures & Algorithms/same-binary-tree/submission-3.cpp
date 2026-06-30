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
    void helper(TreeNode *root, string &s){
        if(root){
            s += root->val;
        }
        else{
            s += "#";
            return;
        }
        if(root->left){
            helper(root->left, s);
        }
        else{
            s += "#";
        }
        if(root->right){
            helper(root->right, s);
        }
        else{
            s += "#";
        }
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string s1, s2;
        helper(p, s1);
        helper(q, s2);
        return s1 == s2;
    }
};
