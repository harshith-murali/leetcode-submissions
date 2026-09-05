class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int missing = 1;
        for(int num : nums){
            if(num > 0 && missing == num){
                missing++;
            }
        }
        return missing;
    }
};