class Solution {
public:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result){
        if(!root) return nullptr;

        root->left = deleteHelper(root->left, st, result);
        root->right = deleteHelper(root->right, st, result);

        if(st.find(root->val) != st.end()){
            if(root->left != nullptr){
                result.push_back(root->left);
            }
            if(root->right != nullptr){
                result.push_back(root->right);
            }
            return nullptr;
        } else {
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        if(deleteHelper(root, st, result) != nullptr){
            result.push_back(root);
        }
        return result;
    }
};