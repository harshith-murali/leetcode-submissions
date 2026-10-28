class Solution {
public:
    unordered_map<char, string> mp = {
    {'1', ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
    {'0', " "}
};
    vector<string> result;
    void solve(int idx, string digits, string temp){
        if(idx == digits.length()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0; i<str.length(); i++){
            temp.push_back(str[i]);
            solve(idx+1,digits,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        solve(0,digits, temp);
        return result;
    }
};