class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;
        for(char ch : word){
            if(ch >= 'A' && ch <= 'Z'){
                upper |= (1 << (ch-'A'));
            }
            else{
                lower |= (1 << (ch-'a'));
            }

        }

        int common = lower & upper;
        return __builtin_popcount(lower & upper);
    }
};