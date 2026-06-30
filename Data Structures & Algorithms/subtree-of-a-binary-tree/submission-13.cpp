class Solution {
public:
    // Helper function to check if two trees are identical
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true; // Both are null, identical
        if (!root || !subRoot) return false; // Only one is null, not identical
        if (root->val != subRoot->val) return false; // Values mismatch
        
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }

    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};