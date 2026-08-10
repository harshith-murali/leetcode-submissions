class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s, int e, int &idx){
        if(s > e) return nullptr;

        int rootVal = preorder[idx];
        int i = s;
        for(; i <= e; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, s, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, e, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};