class Solution {
public:
    int helper(string &s1, string &s2, int idx1 , int idx2 , vector<vector<int>>& dp ){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            return 1 + helper(s1 , s2 , idx1-1 , idx2-1 , dp);
        }
        return dp[idx1][idx2] =  max(helper(s1 , s2 , idx1-1 , idx2, dp) , helper(s1 , s2 , idx1 , idx2-1, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 , vector<int> (n2+1, -1));
        return helper(s1 ,s2 , n1-1 , n2-1 , dp);
    }
};