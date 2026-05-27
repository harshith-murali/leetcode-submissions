class Solution {
public:
    bool palindrome(string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return s2 == s;
    }
    void helper(string s, vector<vector<string>>& ans , vector<string>& partitions){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0; i<s.size(); i++){
            string part = s.substr(0 , i+1);

            if(palindrome(part)){
                partitions.push_back(part);
                helper(s.substr(i+1) , ans, partitions);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        helper(s, ans, partitions);
        return ans;
    }
};