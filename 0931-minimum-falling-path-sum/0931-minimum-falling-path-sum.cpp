class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int j = 0; j < n; j++) {
            dp[n - 1][j] = mat[n - 1][j];
        }

        for(int i = n - 2; i >= 0; i--) {

            for(int j = 0; j < n; j++) {

                int down = dp[i + 1][j];

                int leftDiagonal = 1e9;
                if(j > 0)
                    leftDiagonal = dp[i + 1][j - 1];

                int rightDiagonal = 1e9;
                if(j < n - 1)
                    rightDiagonal = dp[i + 1][j + 1];

                dp[i][j] = mat[i][j] +
                           min(down,
                           min(leftDiagonal, rightDiagonal));
            }
        }

        int mini = INT_MAX;

        for(int j = 0; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }
};