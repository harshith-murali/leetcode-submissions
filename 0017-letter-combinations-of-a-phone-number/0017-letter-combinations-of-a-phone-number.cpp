class Solution {
public:
    void solve(int idx , string digits, string &temp, vector<string> &res, unordered_map<char, string>& mp){
        if(idx == digits.length()){
            res.push_back(temp);
            return;
        }
        char number = digits[idx];
        string letters = mp[number];

        for(int i=0; i<letters.size(); i++){
            // do , explore, undo
            temp.push_back(letters[i]);
            solve(idx + 1, digits, temp, res, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n == 0) return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        vector<string> res;
        solve(0 , digits, temp , res, mp);
        return res;
    }
};