class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0 , high=nums.size()-1;
        int ans=INT_MAX;
        while(low <= high)
        {
            int mid = (low+high)/2;
            ans = min(ans,nums[mid]);

            // Condition 1: Handling the duplicate smokescreen
            if(nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                low++;
                high--;
            }

            // Condition 2: Left half is strictly sorted
            else if(nums[low] <= nums[mid])
            {
                ans=min(nums[low],ans);
                low=mid+1;// Move to right half
            }

            // Condition 3: Right half is strictly sorted
            else
            {
                ans=min(nums[mid],ans);
                high=mid-1;// Move to left half
            }
        }
        return ans;
    }
};