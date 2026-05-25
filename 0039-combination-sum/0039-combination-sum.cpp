class Solution {
public:
    void findCombinations(int idx, int target , vector<int>& candidates , vector<vector<int>>& ans,vector<int>& arr){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(arr);
            }
            return;
        }
        if(candidates[idx] <= target){
            arr.push_back(candidates[idx]);
            findCombinations(idx , target - candidates[idx] , candidates, ans, arr);
            arr.pop_back();
        }
        findCombinations(idx+1 , target, candidates, ans , arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        findCombinations(0 , target, candidates, ans, arr);
        return ans;
    }
};