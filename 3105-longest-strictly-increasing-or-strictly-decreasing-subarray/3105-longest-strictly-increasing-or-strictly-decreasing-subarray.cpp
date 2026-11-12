class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incCnt = 1;
        int decCnt = 1;
        int ans = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                incCnt++;
                decCnt = 1;
            }else if(nums[i] > nums[i+1]){
                decCnt++;
                incCnt = 1;
            }else{
                incCnt = 1;
                decCnt = 1;
            }
            ans = max({ans, incCnt, decCnt});
        }
        return ans;
    }
};