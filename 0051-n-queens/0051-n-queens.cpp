class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col] == 'Q') return false;
    }

    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }

    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}
    void nQueens(int row, int n, vector<vector<string>>& ans,
                 vector<string>& board) {
        if (row == n) {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++) { // place queen on cols
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(row + 1, n, ans, board);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(0, n, ans, board);
        return ans;
    }
};