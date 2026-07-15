class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx < 0)
            return 0;
        if (idx == 0)
            return nums[0];
        if (dp[idx] != -1)
            return dp[idx];
        int notPick = f(idx - 1, nums, dp);

        int pick = nums[idx] + f(idx - 2, nums, dp);
        return dp[idx] = max(notPick, pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n-1, nums, dp);
    }
};