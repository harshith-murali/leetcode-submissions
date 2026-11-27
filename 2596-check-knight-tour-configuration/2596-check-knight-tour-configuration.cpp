class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expValue) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expValue) {
            return false;
        }

        if (expValue == n * n - 1) {
            return true;  // Successfully visited all cells in order
        }

        // Valid knight moves
        vector<pair<int, int>> moves = {
            {-2, -1}, {-2, +1}, {-1, -2}, {-1, +2},
            {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}
        };

        for (auto move : moves) {
            int newR = r + move.first;
            int newC = c + move.second;
            if (isValid(grid, newR, newC, n, expValue + 1)) {
                return true;
            }
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;  // The knight must start at (0,0)
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};
