class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerosFlipped = 0;
        int maxOnes = 0;
        int n = nums.size();
        int l = 0 , r = 0;
        while(r < n){
            if(nums[r] == 0){

                zerosFlipped++;
            }
            while(zerosFlipped > k){
                if(nums[l] == 0){
                    zerosFlipped--;
                }
                l++;
            }
            r++;
            maxOnes = max(maxOnes, r - l);
        }  
        return maxOnes;     
    }
};