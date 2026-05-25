class Solution {
public:
     void solve(int idx, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);
        for(int i=idx; i<arr.size(); i++){
            if(i!= idx && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            solve(i+1, arr, ans, ds);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, arr , ans , ds);
        return ans;
    }
};