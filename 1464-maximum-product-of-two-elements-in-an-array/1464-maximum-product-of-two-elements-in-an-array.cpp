class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int result = 0;
        int n = nums.size();

        for(int i=1; i<n; i++){
            result = max(result , (nums[i] - 1) * (curr_max - 1));
            curr_max = max(curr_max, nums[i]);
        }
        return result;
    }
};