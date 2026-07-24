class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin() , nums.end());
        int startingMax = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == INT_MAX){
                startingMax = i;
                break;
            }
        }
        if(startingMax == -1) return nums.size();
        return startingMax;
    }
};