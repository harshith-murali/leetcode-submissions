class Solution {
public:
    vector<vector<int>> result;

    void fill(TreeNode* root, int targetSum, vector<int>& temp) {
        if (!root) return;

        temp.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right) {
            if (targetSum == 0) {
                result.push_back(temp);
            }
        } else {
            fill(root->left, targetSum, temp);
            fill(root->right, targetSum, temp);
        }

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        fill(root, targetSum, temp);
        return result;
    }
};