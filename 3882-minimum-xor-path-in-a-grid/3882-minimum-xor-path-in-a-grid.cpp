class Solution {
public:
    int solve(int i, int j, int currXor,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        currXor ^= grid[i][j];

        if (i == 0 && j == 0) {
            return currXor;
        }

        if (dp[i][j][currXor] != -1) {
            return dp[i][j][currXor];
        }

        int up = solve(i - 1, j, currXor, grid, dp);
        int left = solve(i, j - 1, currXor, grid, dp);

        return dp[i][j][currXor] = min(up, left);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, -1))
        );

        return solve(m - 1, n - 1, 0, grid, dp);
    }
};