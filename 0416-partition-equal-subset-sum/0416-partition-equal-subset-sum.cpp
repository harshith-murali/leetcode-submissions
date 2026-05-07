class Solution {
public:
    bool f(int idx , int target, vector<int>& nums , vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[0] == target);
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notPick = f(idx-1, target, nums,dp);
        bool pick = false;
        if(target >= nums[idx])
        pick = f(idx - 1 , target-nums[idx], nums,dp);
        return dp[idx][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end() , 0);
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        if(sum % 2 != 0) return false;
        return f(n-1 , sum/2, nums , dp);
    }
};