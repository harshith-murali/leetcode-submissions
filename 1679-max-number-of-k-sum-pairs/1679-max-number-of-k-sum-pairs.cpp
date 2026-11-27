class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 0 , r = n - 1;
        int ops = 0;

        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == k){
                ops++;
                l++;
                r--;
            }else if(sum < k){
                l++;
            }else{
                r--;
            }
        }
        return ops;
    }
};