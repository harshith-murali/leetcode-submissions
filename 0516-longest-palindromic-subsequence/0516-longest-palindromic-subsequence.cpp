class Solution {
public:
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(
            lcs(i - 1, j, s1, s2, dp),
            lcs(i, j - 1, s1, s2, dp)
        );
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();

        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return lcs(n - 1, n - 1, s, t, dp);
    }
};