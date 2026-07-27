class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return root->val == targetSum;
        }

        targetSum -= root->val;

        bool leftPath = hasPathSum(root->left, targetSum);
        bool rightPath = hasPathSum(root->right, targetSum);

        return leftPath || rightPath;
    }
};