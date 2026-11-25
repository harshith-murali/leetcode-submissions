class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = ""; // behave as stack

        int n = num.length();

        for(int i=0; i<n; i++){
            while(res.length() > 0 && res.back() > num[i] && k > 0){
                res.pop_back();
                k--;
            }
            if(res.length() > 0 || num[i] != '0'){
                res.push_back(num[i]);
            }
        }
        while(k > 0 && !res.empty()){
            res.pop_back();
            k--;
        }
        return res == "" ? "0" : res;
    }
};