class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == candidate){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                candidate = nums[i];
                cnt++;
            }
        }
        int check = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == candidate){
                check++;
            }
        }
        return check > nums.size()/2 ? candidate : -1;
    }
};