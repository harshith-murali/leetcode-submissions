class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numIndex;
        for(int i = 0; i < nums.size(); i++) {
            numIndex.push_back({nums[i], i});
        }
        
        sort(numIndex.begin(), numIndex.end());

        int s = 0, e = nums.size() - 1;
        while(s < e) {
            int sum = numIndex[s].first + numIndex[e].first;
            if(sum == target) {
                return {numIndex[s].second, numIndex[e].second};
            }
            else if(sum < target) {
                s++;
            }
            else {
                e--;
            }
        }
        return {}; // no valid pair
    }
};