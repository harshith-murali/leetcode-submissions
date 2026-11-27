class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> st;
        for(int num : arr){
            mp[num]++;
        }
        for(auto it : mp){
            st.insert(it.second);
        }
        return st.size() == mp.size();
    }
};