class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first_pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (first_pos == nums.size() || nums[first_pos] != target) {
            return {-1, -1};
        }

        int last_pos =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return {first_pos, last_pos};
    }
};