class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int l = 0;
        int countZeros = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == 0){
                countZeros++;
            }
            while(countZeros > 1){
                if(nums[l] == 0) countZeros--;
                l++;
            }
            res = max(res, r - l);
        }

        return res;
    }
};