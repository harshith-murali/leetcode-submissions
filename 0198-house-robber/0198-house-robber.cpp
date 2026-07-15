class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for (int idx = 1; idx < n; idx++) {

            int notPick = prev;
            
            int pick = nums[idx];
            if(idx > 1){
                pick = nums[idx] + prev2;
            }
             
            int curr = max(notPick, pick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};