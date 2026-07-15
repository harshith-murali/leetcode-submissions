class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int idx = 1; idx < n; idx++) {

            int notPick = dp[idx - 1];
            
            int pick = nums[idx];
            if(idx > 1){
                pick = nums[idx] + dp[idx - 2];
            }
            dp[idx] = max(notPick, pick);
        }
        return dp[n-1];
    }
};