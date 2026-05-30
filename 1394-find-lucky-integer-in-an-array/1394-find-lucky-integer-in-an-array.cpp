class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi = -1;
        unordered_map<int,int> mp;
        for(int x : arr){
            mp[x]++;
        }
        for(auto it : mp){
            if(it.first == it.second){
                maxi = max(maxi , it.first);
            }
        }
        return maxi;
    }
};