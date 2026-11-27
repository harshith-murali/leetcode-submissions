class Solution {
public:
    void solve(int start, int k, int n, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == k) {
            if (n == 0) res.push_back(temp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; // Pruning: remaining numbers are even larger
            
            temp.push_back(i);
            solve(i + 1, k, n - i, temp, res);
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(1, k, n, temp, res);
        return res;
    }
};