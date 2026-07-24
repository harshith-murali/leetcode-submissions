class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx >= nums.size() - 1) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int minJumps = 1e9;

        for(int jump = 1; jump <= nums[idx]; jump++) {
            int nextJumps = f(idx + jump, nums, dp);

            if(nextJumps != 1e9) {
                minJumps = min(minJumps, 1 + nextJumps);
            }
        }

        return dp[idx] = minJumps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
};