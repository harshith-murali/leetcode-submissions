class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = INT_MIN;
        double sum = 0;
        int l = 0 , r = 0;

        while(r < n){
            sum += nums[r];
            if(r - l + 1 == k){
                ans = max(ans, sum / k) ;
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};