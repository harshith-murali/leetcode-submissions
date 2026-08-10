class Solution {
public:
    void inorder(TreeNode* root, TreeNode*& prev, int& currentFreq, int& maxFreq, vector<int>& result, bool isCollecting) {
        if (!root) return;

        inorder(root->left, prev, currentFreq, maxFreq, result, isCollecting);

        if (prev != nullptr && prev->val == root->val) {
            currentFreq++;
        } else {
            currentFreq = 1;
        }

        if (!isCollecting) {
            maxFreq = max(maxFreq, currentFreq);
        } else if (currentFreq == maxFreq) {
            result.push_back(root->val);
        }

        prev = root;

        inorder(root->right, prev, currentFreq, maxFreq, result, isCollecting);
    }

    vector<int> findMode(TreeNode* root) {
        int currentFreq = 0, maxFreq = 0;
        TreeNode* prev = nullptr;
        vector<int> result;

        inorder(root, prev, currentFreq, maxFreq, result, false);

        prev = nullptr;
        currentFreq = 0;

        inorder(root, prev, currentFreq, maxFreq, result, true);

        return result;
    }
};