class Solution {
public:
    int f(int i, int j , vector<vector<int>>& mat,vector<vector<int>>& dp){
        int n = mat.size();
        if(j < 0 || j >= n) return 1e9;
        if(i==n-1) return mat[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];
        return dp[i][j] = mat[i][j] + min(
            f(i+1,j,mat,dp),
            min(
                f(i+1,j+1 , mat, dp),
                f(i+1,j-1 , mat , dp)
                )
            );
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            mini = min(mini, f(0,j,mat,dp));
        }
        return mini;
    }
};